/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:34:54 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/30 11:34:57 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	after_party_clean(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->last_meal_lock);
}

int	f_wrong_value_exit(void)
{
	write(1, ">>> provided values are too low or you int overflow\n", 52);
	return (3);
}

int	f_wrong_argv_exit(void)
{
	write(1, ">>> incorrect amount of arguments :(\n", 37);
	write(1, ">>> EXAMPLE:\n", 13);
	write(1, "./philo <N of philosophers> <time to die> <time to eat>", 55);
	write(1, " <time to sleep> <must eat N of time>\n", 38);
	return (3);
}
