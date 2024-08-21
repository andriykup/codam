/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:15:49 by aconvent          #+#    #+#             */
/*   Updated: 2024/07/25 13:34:02 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

t_command	*init_command(void)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (new_command == NULL)
		return (NULL);
	new_command->args = NULL;
	new_command->redir = NULL;
	new_command->redirected = false;
	new_command->next = NULL;
	return (new_command);
}

t_redir	*redir_init(void)
{
	t_redir	*new_redir;

	new_redir = malloc(sizeof(t_redir));
	if (new_redir == NULL)
		return (NULL);
	new_redir->file_name = NULL;
	new_redir->delimiter = NULL;
	new_redir->redir = NULL;
	new_redir->next = NULL;
	return (new_redir);
}

void	mini_init(t_mini_shell **mini_shell, t_env **my_env)
{
	(*mini_shell)->parsed_input = NULL;
	(*mini_shell)->commands = NULL;
	(*mini_shell)->local_environ = NULL;
	(*mini_shell)->pipefd = NULL;
	(*mini_shell)->pipes = -1;
	(*mini_shell)->quotes = true;
	(*mini_shell)->in_quotes = true;
	(*mini_shell)->env_value = NULL;
	(*mini_shell)->ret_value = 0;
	(*mini_shell)->my_paths = get_env_path(*my_env);
}

t_env	*ft_new_node(char	**splited_env_var)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	if (new_env == NULL)
		return (NULL);
	new_env->prev = NULL;
	new_env->next = NULL;
	new_env->key = ft_strdup(splited_env_var[0]);
	new_env->value = ft_strdup(splited_env_var[1]);
	return (new_env);
}
