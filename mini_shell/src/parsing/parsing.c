/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:14:39 by aconvent          #+#    #+#             */
/*   Updated: 2024/08/05 13:43:39 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

int	command_list(t_mini_shell **mini_shell, t_env **env)
{
	t_command	*cmd_head;
	t_command	*cmd;
	int			i;

	cmd_head = NULL;
	cmd = NULL;
	i = 0;
	while ((*mini_shell)->parsed_input[i] != NULL)
	{
		cmd = init_command();
		if (cmd == NULL)
			return (-1);
		if ((get_command((*mini_shell)->parsed_input[i], \
				&cmd, env, *mini_shell)) == -1)
		{
			add_command_to_end(&cmd_head, cmd);
			(*mini_shell)->commands = cmd_head;
			free_struct(mini_shell);
			return (-1);
		}
		add_command_to_end(&cmd_head, cmd);
		i++;
	}
	(*mini_shell)->commands = cmd_head;
	return (0);
}

int	parse_quotes_args(t_mini_shell **mini_shell)
{
	t_command	*current_cmd ;
	char		*processed_arg;
	int			i;

	current_cmd = (*mini_shell)->commands;
	while (current_cmd)
	{
		i = -1;
		while (current_cmd->args && current_cmd->args[++i])
		{
			processed_arg = command_quotes(current_cmd->args[i]);
			if (processed_arg)
			{
				free(current_cmd->args[i]);
				current_cmd->args[i] = processed_arg;
			}
			else
			{
				write(2, "Not hadnled by mini_shell\n", 27);
				return (-1);
			}
		}
		current_cmd = current_cmd->next;
	}
	return (0);
}
