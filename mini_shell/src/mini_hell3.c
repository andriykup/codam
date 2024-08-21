/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hell3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:48:38 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/22 10:48:41 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

static void	ft_exec_heredoc_dup(int *file_fd, t_redir *redir)
{
	if (ft_strcmp(redir->redir, ">") == 0)
	{
		file_open_check(redir, file_fd);
		if (*file_fd == -1)
		{
			perror("open failure for output redirection");
			exit(EXIT_FAILURE);
		}
		if (dup2(*file_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 failure for output redirection");
			close(*file_fd);
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_strcmp(redir->redir, ">>") == 0)
	{
		file_open_check(redir, file_fd);
		if (dup2(*file_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 failure for append redirection");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_exec_dup2(t_redir *redir, t_mini_shell **mini_shell, t_env **my_env)
{
	int		file_fd;
	char	temp_file[2];

	file_fd = 0;
	ft_exec_dup2_1(redir, &file_fd);
	ft_exec_dup2_2(redir, &file_fd);
	if (ft_strcmp(redir->redir, "<<") == 0)
	{
		temp_file[0] = '1';
		temp_file[1] = '\0';
		heredoc_tempfile(redir->delimiter, temp_file, mini_shell, my_env);
		file_fd = open(temp_file, O_RDONLY);
		if (file_fd == -1 || dup2(file_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 failure for heredoc redirection");
			exit(EXIT_FAILURE);
		}
		while (redir->next)
		{
			ft_exec_heredoc_dup(&file_fd, redir);
			redir = redir->next;
		}
		unlink(temp_file);
	}
	close(file_fd);
}

void	ft_exec_dup2_1(t_redir *redir, int *file_fd)
{
	if (ft_strcmp((*redir).redir, "<") == 0)
	{
		file_open_check(redir, file_fd);
		if (dup2(*file_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 failure for input redirection");
			close(*file_fd);
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_strcmp(redir->redir, ">") == 0)
	{
		file_open_check(redir, file_fd);
		if (*file_fd == -1)
		{
			perror("open failure for output redirection");
			exit(EXIT_FAILURE);
		}
		if (dup2(*file_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 failure for output redirection");
			close(*file_fd);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_exec_dup2_2(t_redir *redir, int *file_fd)
{
	if (ft_strcmp(redir->redir, ">>") == 0)
	{
		file_open_check(redir, file_fd);
		if (dup2(*file_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 failure for append redirection");
			exit(EXIT_FAILURE);
		}
	}
}
