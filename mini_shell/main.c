/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:20:05 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 16:04:37 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini_hell.h"

sig_atomic_t	g_signal_status = 0;

static int	ft_check_null_command(t_mini_shell *mini_shell)
{
	t_command	*command_curr;

	command_curr = mini_shell->commands;
	while (command_curr)
	{
		if (command_curr->args[0] == NULL)
			return (-1);
		command_curr = command_curr->next;
	}
	return (0);
}

int	mini_hell_end(t_mini_shell **mini_shell,
	t_env **my_env, int *i, char *input)
{
	(*mini_shell)->parsed_input = ft_split_pipes(input);
	free(input);
	if ((*mini_shell)->parsed_input[0] == NULL)
		return (4);
	while ((*mini_shell)->parsed_input[(*i)++] != NULL)
		(*mini_shell)->pipes++;
	if (command_list(mini_shell, my_env) == -1)
	{
		(*mini_shell)->ret_value = 2;
		return (4);
	}
	if (ft_check_null_command(*mini_shell) == -1)
	{
		free_struct(mini_shell);
		return (4);
	}
	if (parse_quotes_args(mini_shell) == 0)
	{
		my_executions(mini_shell, my_env);
		ft_free_2arr((*mini_shell)->splitted_paths);
		ft_free_2arr((*mini_shell)->local_environ);
	}
	free_struct(mini_shell);
	return (0);
}

static void	mini_hell(t_mini_shell **mini_shell, t_env **my_env)
{
	int		i;
	char	*input;

	while (1)
	{
		i = 0;
		(*mini_shell)->pipes = -1;
		input = readline("minishell: ");
		ft_signal_check(mini_shell);
		if (input == NULL)
			ft_no_input(mini_shell, my_env, input);
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		add_history(input);
		input = ft_spaceout(input);
		if (ft_input_check(input) == 4)
			continue ;
		if (ft_check_input_0(mini_shell, input) == 4)
			continue ;
		if (mini_hell_end(mini_shell, my_env, &i, input) == 4)
			continue ;
	}
}

int	main(int argc, char **argv)
{
	t_mini_shell	*mini_shell;
	t_env			*my_env;

	(void)argv;
	if (argc != 1)
	{
		write(2, "minishell: ", 11);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory\n", 29);
		exit (127);
	}
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	my_env = NULL;
	mini_shell = (t_mini_shell *)malloc(sizeof(t_mini_shell));
	if (mini_shell == NULL)
		exit (1);
	if (set_my_env(&my_env) == -1)
	{
		exit (1);
	}
	mini_init(&mini_shell, &my_env);
	mini_hell(&mini_shell, &my_env);
	return (0);
}
