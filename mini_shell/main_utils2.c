/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:24:02 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 14:46:34 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini_hell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal_status = 1;
}

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(130);
}

void	ft_no_input(t_mini_shell **mini_shell, t_env **my_env, char *input)
{
	printf(GRN"exit\n");
	unlink("1");
	free_struct(mini_shell);
	free_my_env(my_env);
	free(input);
	exit ((*mini_shell)->ret_value);
}

void	ft_signal_check(t_mini_shell **mini_shell)
{
	if (g_signal_status != 0)
	{
		(*mini_shell)->ret_value = 130;
		g_signal_status = 0;
		unlink("1");
	}
}
