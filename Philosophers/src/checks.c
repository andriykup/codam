/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:32:16 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/13 19:32:18 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_times_to_eat(t_program *program)
{
	int	i;

	if (program->num_times_to_eat == -1)
		return (0);
	i = 0;
	while (i < program->num_of_philos)
	{
		pthread_mutex_lock(&program->meal_lock);
		if (program->num_times_to_eat > program->philos[i].meals_eaten)
		{
			pthread_mutex_unlock(&program->meal_lock);
			return (0);
		}
		pthread_mutex_unlock(&program->meal_lock);
		i++;
	}
	return (1);
}

int	check_dead(t_program *program)
{
	int	i;
	int	time;

	i = 0;
	time = get_current_time() - program->philos[i].start_time;
	while (i < program->num_of_philos)
	{
		pthread_mutex_lock(&program->last_meal_lock);
		if ((time - program->philos[i].last_meal) >= program->time_to_die)
		{
			pthread_mutex_unlock(&program->last_meal_lock);
			printf("%d %d died\n", time, program->philos[i].id);
			pthread_mutex_lock(&program->dead_lock);
			pthread_mutex_lock(&program->write_lock);
			program->dead_flag = 1;
			program->write_flag_lock = 1;
			pthread_mutex_unlock(&program->write_lock);
			pthread_mutex_unlock(&program->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&program->last_meal_lock);
		i++;
	}
	return (0);
}
