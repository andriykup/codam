/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:09:02 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/28 21:09:05 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_program(t_philo *philos, t_program *program)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->last_meal_lock, NULL);
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	init_program(philos, program);
	while (i < program->num_of_philos)
	{
		philos[i].program = program;
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[program->num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
