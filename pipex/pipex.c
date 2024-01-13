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
		return (perror("pipe error"));
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork error"));
	if (pid1 == 0)
		exec_child_process_1(f1, end, argv, paths_envp);
	waitpid(pid1, NULL, 0);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork error"));
	if (pid2 == 0)
		exec_child_process_2(f2, end, argv, paths_envp);
	close(end[0]);
	close(end[1]);
	free_mem(paths_envp);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
		return (perror("wrong ammount of arguments"), -1);
	f1 = open(argv[1], O_RDONLY, 0777);
	if (f1 == -1)
		return (perror("not able to open input file"), -2);
	f2 = open(argv[4], O_RDWR | O_CREAT, 0777);
	if (f2 == -1)
		return (perror("not able to open output file"), -3);
	ft_pipex(f1, f2, argv, envp);
	return (0);
}
