/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:40 by ankupins          #+#    #+#             */
/*   Updated: 2024/01/12 12:30:43 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_mem(char **paths_envp)
{
	int	y;

	y = 0;
	while (paths_envp[y])
	{
		free(paths_envp[y]);
		y++;
	}
	free (paths_envp);
}

void	exec_child_process_1(int f1, int *end, char **argv, char **paths_envp)
{
	char	**cmd_args;
	char	*cmd_path;

	if (dup2(f1, STDIN_FILENO) == -1)
		return (perror("dup2 error"));
	if (dup2(end[1], STDOUT_FILENO) == -1)
		return (perror("dup2 error"));
	close(end[0]);
	close(end[1]);
	close(f1);
	cmd_args = ft_split(argv[2], ' ');
	if (cmd_args == NULL)
		return (perror("error while splitting cmd args"));
	cmd_path = find_cmd_path(paths_envp, cmd_args[0]);
	if (cmd_path == NULL)
	{
		free(cmd_args);
		return (perror("error while finding cmd path"));
	}
	if ((execve(cmd_path, cmd_args, NULL)) == -1)
		exit(EXIT_FAILURE);
}

void	exec_child_process_2(int f2, int *end, char **argv, char **paths_envp)
{
	char	**cmd_args;
	char	*cmd_path;

	if (dup2(f2, STDOUT_FILENO) == -1)
		return (perror("dup2 error"));
	if (dup2(end[0], STDIN_FILENO) == -1)
		return (perror("dup2 error"));
	close(end[0]);
	close(end[1]);
	close(f2);
	cmd_args = ft_split(argv[3], ' ');
	if (cmd_args == NULL)
		return (perror("error while splitting cmd args"));
	cmd_path = find_cmd_path(paths_envp, cmd_args[0]);
	if (cmd_path == NULL)
	{
		free(cmd_args);
		return (perror("error while finding cmd path"));
	}
	if ((execve(cmd_path, cmd_args, NULL)) == -1)
		exit(EXIT_FAILURE);
}

char	**get_env_path(char **envp)
{
	char	*path;

	path = NULL;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp != NULL)
		path = *envp + 5;
	if (*path != '\0')
		return (ft_split(path, ':'));
	free(path);
	return (NULL);
}

char	*find_cmd_path(char **paths_envp, char *cmd)
{
	int		i;
	char	*full_cmd;
	char	*ret;

	full_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (paths_envp[i])
	{
		ret = ft_strjoin(paths_envp[i], full_cmd);
		if (access(ret, X_OK) != -1)
		{
			free(full_cmd);
			return (ret);
		}
		i++;
	}
	free(ret);
	free(full_cmd);
	return (NULL);
}
