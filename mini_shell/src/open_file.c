/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 06:51:28 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 14:08:26 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

static void	redir_check_1(t_redir *temp_redir, t_redir *redir, int *file_fd)
{
	if (ft_strcmp(temp_redir->redir, ">") == 0)
	{
		while (temp_redir)
		{
			*file_fd = open(redir->file_name,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (*file_fd == -1)
			{
				ft_error(redir->file_name, NULL);
				exit (1);
			}
			if (temp_redir->next == NULL)
				return ;
			temp_redir = temp_redir->next;
		}
	}
}

static void	redir_check_2(t_redir *temp_redir, t_redir *redir, int *file_fd)
{
	if (ft_strcmp(temp_redir->redir, "<") == 0)
	{
		while (temp_redir)
		{
			*file_fd = open(redir->file_name, O_RDONLY);
			if (*file_fd == -1)
			{
				ft_error(redir->file_name, NULL);
				exit (1);
			}
			if (temp_redir->next == NULL)
				return ;
			temp_redir = temp_redir->next;
		}
	}
}

void	file_open_check(t_redir *redir, int *file_fd)
{
	t_redir	*temp_redir;

	temp_redir = redir;
	redir_check_1(temp_redir, redir, file_fd);
	redir_check_2(temp_redir, redir, file_fd);
	if (ft_strcmp(temp_redir->redir, ">>") == 0)
	{
		while (temp_redir)
		{
			*file_fd = open(redir->file_name,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (*file_fd == -1)
			{
				ft_error(redir->file_name, NULL);
				exit (1);
			}
			if (temp_redir->next == NULL)
				return ;
			temp_redir = temp_redir->next;
		}
	}
}
