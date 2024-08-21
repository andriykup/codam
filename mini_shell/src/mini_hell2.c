/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:11:01 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 14:04:29 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

static void	ft_start_child_fd(t_mini_shell **mini_shell, int i)
{
	if (i != 0)
	{
		if (dup2((*mini_shell)->pipefd[(i - 1) * 2], STDIN_FILENO) == -1)
		{
			perror("dup2 failuer");
			exit(EXIT_FAILURE);
		}
	}
	if (i != (*mini_shell)->pipes)
	{
		if (dup2((*mini_shell)->pipefd[i * 2 + 1], STDOUT_FILENO) == -1)
		{
			perror("dup2 failuer");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_start_child(t_mini_shell **mini_shell, int i,
	t_command *command_current, t_env **my_env)
{
	t_redir	*redir;

	if (command_current->redirected)
	{
		redir = command_current->redir;
		while (redir)
		{
			if (ft_strcmp(redir->redir, "<<") == 0)
			{
				while (ft_strcmp(redir->redir, "<<")
					== 0 && (redir->next && ft_strcmp(redir->next->redir,
							"<<") == 0))
					redir = redir->next;
			}
			ft_exec_dup2(redir, mini_shell, my_env);
			redir = redir->next;
		}
	}
	ft_start_child_fd(mini_shell, i);
}

void	ft_end_child(t_mini_shell **mini_shell,
	t_command *command_current, t_env **my_env)
{
	char	*cmd_path;
	int		j;

	j = 0;
	while (j < 2 * ((*mini_shell)->pipes))
	{
		close((*mini_shell)->pipefd[j]);
		j++;
	}
	if (builtin_com_pipe(mini_shell, my_env, command_current->args) == 0)
	{
		free((*mini_shell)->pipefd);
		(*mini_shell)->pipefd = NULL;
		exit (0);
	}
	else
	{
		if (ft_strncmp(command_current->args[0], "exit", 6) == 0)
			exit(0);
		cmd_path = find_cmd_path((*mini_shell)->splitted_paths,
				command_current->args[0]);
		if ((execve(cmd_path, command_current->args,
					(*mini_shell)->local_environ)) < 0)
			ft_execve_fail(command_current->args[0], cmd_path);
	}
}

int	my_execution_p2(t_mini_shell **mini_shell, t_command	*command_current)
{
	if ((*mini_shell)->pipes != 0 && (ft_strncmp(command_current->args[0],
				"exit", 7) == 0))
	{
		command_current = command_current->next;
		return (0);
	}
	if ((*mini_shell)->pipes != 0 && (ft_strncmp(command_current->args[0],
				"cd", 3) == 0))
	{
		command_current = command_current->next;
		return (0);
	}
	if ((*mini_shell)->pipes != 0 && (ft_strncmp(command_current->args[0],
				"export", 7) == 0))
	{
		command_current = command_current->next;
		return (0);
	}
	if ((*mini_shell)->pipes != 0 && (ft_strncmp(command_current->args[0],
				"unset", 6) == 0))
	{
		command_current = command_current->next;
		return (0);
	}
	return (1);
}

void	my_execution_init(t_mini_shell **mini_shell, t_env **my_env)
{
	if ((*mini_shell)->my_paths != NULL)
		free((*mini_shell)->my_paths);
	(*mini_shell)->my_paths = get_env_path(*my_env);
	(*mini_shell)->splitted_paths = ft_split((*mini_shell)->my_paths, ':');
	ft_pipefd_malloc(mini_shell);
	create_pipes((*mini_shell)->pipefd, *(*mini_shell));
	ft_local_environ(mini_shell, *my_env);
}
