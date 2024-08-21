/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:35:41 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/09 16:01:16 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

void	ft_fd_check(int fd)
{
	if (fd < 0)
	{
		perror("open file for heredoc");
		exit (EXIT_FAILURE);
	}
}

void	error_export(char *str)
{
	write(2, "export: ", 8);
	write(2, str, ft_strlen(str));
	write(2, ": not a valid identifier\n", 26);
}

void	ft_execve_fail(char *args, char *path)
{
	ft_error(args, CMD);
	free(path);
	path = NULL;
	exit(127);
}

void	ft_exit_error(int x, t_mini_shell **mini_shell, int length)
{
	if (x == 1)
	{
		write(2, "minishell: ", 11);
		write(2, (*mini_shell)->commands->args[0], length);
		write(2, ": numeric argument required\n", 29);
	}
	else
	{
		write(2, "minishell: ", 11);
		write(2, (*mini_shell)->commands->args[0], length);
		write(2, ": too many arguments\n", 21);
	}
}

void	*ft_error(char *cmd, char *err_msg)
{
	write(2, BLD RED"❗minishell: ", (ft_strlen(RED) + ft_strlen(BLD) + 14));
	write(2, RST RED, ft_strlen(RED) + ft_strlen(RST));
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	if (err_msg)
		write(2, err_msg, ft_strlen(err_msg));
	else
		perror("");
	printf(RST);
	return (NULL);
}
