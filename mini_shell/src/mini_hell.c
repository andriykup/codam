/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:40:20 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/09 15:08:40 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

char	*find_cmd_f(char **paths_envp, char *full_cmd)
{
	char	*ret;
	int		i;

	i = 0;
	while (paths_envp[i])
	{
		ret = ft_strjoin(paths_envp[i], full_cmd);
		if (ret == NULL)
			return (NULL);
		if (access(ret, X_OK) != -1)
		{
			free(full_cmd);
			return (ret);
		}
		free(ret);
		i++;
	}
	free(full_cmd);
	return (NULL);
}

char	*find_cmd_path(char **paths_envp, char *cmd)
{
	char	*full_cmd;
	char	*ret;

	if (access(cmd, X_OK) != -1)
		return (cmd);
	full_cmd = ft_strjoin("/", cmd);
	if (full_cmd == NULL)
		return (NULL);
	if (paths_envp == NULL || cmd == NULL || ft_strncmp(cmd, "exit", 6) == 0)
		return (free(full_cmd), NULL);
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) != -1)
		{
			ret = ft_strdup(cmd);
			if (ret == NULL)
				return (NULL);
			return (ret);
		}
		return (free(full_cmd), NULL);
	}
	ret = find_cmd_f(paths_envp, full_cmd);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

static void	ft_child_process_exec(t_mini_shell **mini_shell,
	t_env **my_env, int i, t_command *command_current)
{
	char	*argv[2];

	if (ft_strncmp(command_current->args[0], "./", 2) == 0)
	{
		argv[0] = command_current->args[0];
		argv[1] = NULL;
		if (execve(command_current->args[0], argv,
				(*mini_shell)->local_environ) < 0)
		{
			ft_error(command_current->args[0], NULL);
			if (errno == 13)
				exit (126);
			else
				exit (127);
		}
	}
	ft_start_child(mini_shell, i, command_current, my_env);
	ft_end_child(mini_shell, command_current, my_env);
}

void	my_executions(t_mini_shell **mini_shell, t_env **my_env)
{
	int			pid;
	t_command	*command_current;
	int			i;

	command_current = (*mini_shell)->commands;
	my_execution_init(mini_shell, my_env);
	i = -1;
	while (++i < ((*mini_shell)->pipes + 1))
	{
		if ((*mini_shell)->pipes != 0 && (my_execution_p2(mini_shell,
					command_current) == 0))
		{
			command_current = command_current->next;
			continue ;
		}
		if (builtin_com(mini_shell, my_env, command_current->args) == 0)
			return ;
		pid = fork();
		if (pid == -1)
			exit (-1);
		if (pid == 0)
			ft_child_process_exec(mini_shell, my_env, i, command_current);
		command_current = command_current->next;
	}
	ft_exec_close(mini_shell);
}
