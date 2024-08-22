/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:58:55 by ankupins          #+#    #+#             */
/*   Updated: 2024/06/14 13:58:57 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_atoi(char *nptr)
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
		if (res < 0)
			return (-1);
		i++;
	}
	return (res * sign);
}

static int	argv_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

static int	input_parsing(char **argv, t_program *program)
{
	program->num_of_philos = ft_atoi(argv[1]);
	if (program->num_of_philos > 200)
	{
		write(2, "to much philosophers, please keep it below 201\n", 47);
		return (-1);
	}
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (program->time_to_die < 60
		|| program->time_to_eat < 60
		|| program->time_to_sleep < 60)
	{
		f_wrong_value_exit();
		return (-1);
	}
	if (argv[5] != NULL)
	{
		program->num_times_to_eat = ft_atoi(argv[5]);
		if (program->num_times_to_eat == -1)
			return (-1);
	}
	else
		program->num_times_to_eat = -1;
	return (0);
}

int	input_check(int argc, char **argv, t_program *program)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv_check(argv[i]) == -1)
		{
			write(1, ">>> input should contain only positive numbers :(\n", 50);
			return (-1);
		}
		i++;
	}
	if (input_parsing(argv, program) == -1)
		return (-1);
	return (0);
}
