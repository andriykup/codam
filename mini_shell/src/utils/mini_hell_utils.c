/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:33:06 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 13:58:54 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

static int	delimiter_check(char *line, const char *delimiter)
{
	if (ft_strcmp(line, delimiter) == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

void	heredoc_tempfile(const char *delimiter, char *temp_file,
							t_mini_shell **mini_shell, t_env **my_env)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	ft_fd_check(fd);
	signal(SIGINT, handle_sigint_heredoc);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (delimiter_check(line, delimiter) == 1)
			break ;
		line = dquotes_work(line, my_env, *mini_shell);
		temp = ft_strdup(line);
		free(line);
		line = command_quotes(temp);
		if (!line)
			return ;
		heredoc_tempfile1(fd, line, temp);
	}
	close(fd);
	signal(SIGINT, handle_sigint);
}

int	builtin_com_pipe(t_mini_shell **mini_shell, t_env **my_env, char **cmd_args)
{
	if (ft_strncmp(cmd_args[0], "env", 4) == 0)
	{
		(*mini_shell)->ret_value = com_env(cmd_args, my_env, mini_shell);
		return (0);
	}
	else if (ft_strncmp(cmd_args[0], "pwd", 4) == 0)
	{
		(*mini_shell)->ret_value = com_pwd(mini_shell);
		return (0);
	}
	else if (ft_strncmp(cmd_args[0], "echo", 5) == 0)
	{
		(*mini_shell)->ret_value = com_echo(cmd_args, mini_shell);
		return (0);
	}
	return (1);
}

static int	builtin_com_1(t_mini_shell **mini_shell,
							t_env **my_env, char **cmd_args)
{
	if (ft_strncmp(cmd_args[0], "export", 7) == 0)
	{
		com_export(my_env, cmd_args, mini_shell);
		return (0);
	}
	else if (ft_strncmp(cmd_args[0], "unset", 6) == 0)
	{
		com_unset(my_env, cmd_args[1], mini_shell);
		return (0);
	}
	return (1);
}

int	builtin_com(t_mini_shell **mini_shell, t_env **my_env, char **cmd_args)
{
	if (builtin_com_1(mini_shell, my_env, cmd_args) == 0)
		return (0);
	else if (ft_strncmp(cmd_args[0], "cd", 3) == 0)
	{
		if (cmd_args[1] == NULL)
			empty_cd(*my_env, mini_shell);
		else if (ft_strcmp(cmd_args[1], "~") == 0)
			empty_cd(*my_env, mini_shell);
		else if (cmd_args[2] != NULL)
		{
			ft_error("cd", ARGG);
			(*mini_shell)->ret_value = 1;
		}
		else
			com_cd(cmd_args[1], *my_env, mini_shell);
		return (0);
	}
	else if (ft_strncmp(cmd_args[0], "exit", 7) == 0)
	{
		if (com_exit(mini_shell, my_env) == 0)
			return (0);
	}
	return (1);
}
