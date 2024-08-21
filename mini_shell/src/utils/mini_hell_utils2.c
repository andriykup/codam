/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:58:01 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 14:03:49 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

void	heredoc_tempfile1(int fd, char	*line, char	*temp)
{
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(temp);
	free(line);
}

void	ft_exec_close(t_mini_shell **mini_shell)
{
	int	i;
	int	status;

	i = 0;
	while (i < 2 * (*mini_shell)->pipes)
	{
		close((*mini_shell)->pipefd[i]);
		i++;
	}
	i = 0;
	while (i < (*mini_shell)->pipes + 1)
	{
		wait(&status);
		(*mini_shell)->ret_value = ((status >> 8) & 0xFF);
		i++;
	}
	free((*mini_shell)->pipefd);
	(*mini_shell)->pipefd = NULL;
}

void	create_pipes(int *pipefd, t_mini_shell mini_shell)
{
	int	i;

	i = 0;
	while (i < mini_shell.pipes)
	{
		if (pipe(pipefd + 2 * i) == -1)
		{
			printf(RED"Error : PIPE creation Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_pipefd_malloc(t_mini_shell **mini_shell)
{
	if ((*mini_shell)->pipefd != NULL)
		free((*mini_shell)->pipefd);
	(*mini_shell)->pipefd = malloc(sizeof(int) * (2 * (*mini_shell)->pipes));
	if ((*mini_shell)->pipefd == NULL)
	{
		printf(RED"Failed to allocate memory for pipefd");
		exit (-1);
	}
}

int	ft_num_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
