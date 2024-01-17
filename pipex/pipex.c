/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:31 by ankupins          #+#    #+#             */
/*   Updated: 2024/01/12 12:30:33 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex in.txt "ls -l" "wc -w" out.txt
// valgrind --leak-check=yes ./pipex in.txt "ls -l" "wc -w" out.txt
#include "pipex.h"

static void	ft_pipex(int f1, int f2, char **argv, char **envp)
{
	int		end[2];
	int		pid1;
	int		pid2;
	char	**paths_envp;

	paths_envp = get_env_path(envp);
	if (pipe(end) == -1)
		exit_error("pipe error");
	pid1 = fork();
	if (pid1 == -1)
		exit_error("fork error");
	if (pid1 == 0)
		exec_child_process_1(f1, end, argv, paths_envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_error("fork error");
	if (pid2 == 0)
		exec_child_process_2(f2, end, argv, paths_envp);
	close(end[0]);
	close(end[1]);
	free_mem(paths_envp);
	wait(NULL);
	wait(NULL);
}

void	exec_child_process_1(int f1, int *end, char **argv, char **paths_envp)
{
	char	**cmd_args;
	char	*cmd_path;

	if (dup2(f1, STDIN_FILENO) == -1)
		exit_error("dup2 error");
	if (dup2(end[1], STDOUT_FILENO) == -1)
		exit_error("dup2 error");
	close(end[0]);
	close(end[1]);
	close(f1);
	cmd_args = ft_split(argv[2], ' ');
	if (cmd_args == NULL)
		exit_error("error while splitting cmd args");
	cmd_path = find_cmd_path(paths_envp, cmd_args[0]);
	if (cmd_path == NULL)
	{
		free(cmd_args);
		exit_error("error cmd_path");
	}
	if ((execve(cmd_path, cmd_args, NULL)) == -1)
		exit_error("excve child 1 error");
}

void	exec_child_process_2(int f2, int *end, char **argv, char **paths_envp)
{
	char	**cmd_args;
	char	*cmd_path;

	if (dup2(f2, STDOUT_FILENO) == -1)
		exit_error("dup2 error");
	if (dup2(end[0], STDIN_FILENO) == -1)
		exit_error("dup2 error");
	close(end[0]);
	close(end[1]);
	close(f2);
	cmd_args = ft_split(argv[3], ' ');
	if (cmd_args == NULL)
		exit_error("error while splitting cmd args");
	cmd_path = find_cmd_path(paths_envp, cmd_args[0]);
	if (cmd_path == NULL)
	{
		free(cmd_args);
		exit_error("error cmd_path");
	}
	if ((execve(cmd_path, cmd_args, NULL)) == -1)
		exit_error("excve child 2 error");
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
		exit_error("wrong ammount of arguments");
	f1 = open(argv[1], O_RDONLY, 0777);
	if (f1 == -1)
		exit_error("not able to open input file");
	f2 = open(argv[4], O_RDWR | O_CREAT, 0777);
	if (f2 == -1)
		exit_error("not able to open output file");
	ft_pipex(f1, f2, argv, envp);
	exit(EXIT_SUCCESS);
}
