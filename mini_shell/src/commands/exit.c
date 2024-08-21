/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:52:32 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/09 15:04:30 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

void	free_command_struct(t_mini_shell **mini_shell)
{
	t_command	*cmd;
	t_command	*next_cmd;

	cmd = (*mini_shell)->commands;
	while (cmd != NULL)
	{
		next_cmd = cmd->next;
		if (cmd->args != NULL)
			ft_free_2arr(cmd->args);
		if (cmd->redirected == true)
		{
			free_redirections(&cmd);
		}
		free(cmd);
		cmd = NULL;
		cmd = next_cmd;
	}
	(*mini_shell)->commands = NULL;
}

void	free_redirections(t_command **cmd)
{
	t_redir	*next_redir;

	while ((*cmd)->redir)
	{
		next_redir = (*cmd)->redir->next;
		if ((*cmd)->redir->file_name != NULL)
		{
			free((*cmd)->redir->file_name);
			(*cmd)->redir->file_name = NULL;
		}
		if ((*cmd)->redir->delimiter != NULL)
		{
			free((*cmd)->redir->delimiter);
			(*cmd)->redir->delimiter = NULL;
		}
		free((*cmd)->redir->redir);
		free((*cmd)->redir);
		(*cmd)->redir = next_redir;
	}
	free((*cmd)->redir);
	(*cmd)->redir = NULL;
}

static int	ft_exit_if(t_mini_shell **mini_shell)
{
	int	exit_status;
	int	length;

	length = ft_strlen((*mini_shell)->commands->args[0]);
	exit_status = 0;
	if ((*mini_shell)->commands->args[1] != NULL)
	{
		if (ft_num_check((*mini_shell)->commands->args[1]) == 1)
		{
			ft_exit_error(1, mini_shell, length);
			(*mini_shell)->ret_value = 2;
			exit (2);
		}
		if ((*mini_shell)->commands->args[2] != NULL)
		{
			ft_exit_error(0, mini_shell, length);
			(*mini_shell)->ret_value = 1;
			return (1);
		}
		exit_status = ft_atoi((*mini_shell)->commands->args[1]);
	}
	return (exit_status);
}

int	com_exit(t_mini_shell **mini_shell, t_env **my_env)
{
	int	exit_status;

	exit_status = 0;
	if ((*mini_shell)->commands->args[1] != NULL)
	{
		exit_status = ft_exit_if(mini_shell);
		(*mini_shell)->ret_value = exit_status;
	}
	free_my_env(my_env);
	ft_free_2arr((*mini_shell)->local_environ);
	ft_free_2arr((*mini_shell)->splitted_paths);
	free_struct(mini_shell);
	if ((*mini_shell)->pipefd != NULL)
		free((*mini_shell)->pipefd);
	(*mini_shell)->pipefd = NULL;
	unlink("1");
	printf("exit\n");
	exit ((*mini_shell)->ret_value);
}
