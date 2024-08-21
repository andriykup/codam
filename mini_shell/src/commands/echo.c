/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:00:23 by aconvent          #+#    #+#             */
/*   Updated: 2024/07/07 14:58:38 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

static void	flag_check(int flag)
{
	if (flag != 1)
		printf("\n");
}

static int	ft_str_check(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_print_arr(char **command, int i)
{
	while (command[i])
	{
		printf("%s", command[i]);
		if (command[i + 1] != NULL)
			printf(" ");
		i++;
	}
}

int	com_echo(char **command, t_mini_shell **mini_shell)
{
	int	flag;
	int	i;

	i = 1;
	flag = 0;
	if (command[i] == NULL)
		return (printf("\n"), 0);
	while (command[i])
	{
		if (command[i][0] != '-')
			break ;
		if (command[i][1] != 'n')
			break ;
		if (ft_str_check(command[i]) == 1)
			break ;
		flag = 1;
		i++;
	}
	ft_print_arr(command, i);
	flag_check(flag);
	(*mini_shell)->ret_value = 0;
	return (0);
}
