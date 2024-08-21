/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:20:49 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/15 21:20:50 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	only_one_philo( t_philo *philos)
{
	pthread_mutex_lock(philos->r_fork);
	ft_message_print("has taken a fork", philos);
	usleep(philos->program->time_to_die * 1000);
	ft_message_print("died", philos);
	pthread_mutex_unlock(philos->l_fork);
}

static int	start_routine(t_philo *philos)
{
	if (philos->program->num_of_philos == 1)
	{
		only_one_philo(philos);
		return (1);
	}
	if (philos->id % 2 == 0)
	{
		ft_message_print("is thinking", philos);
		usleep(philos->program->time_to_sleep * 1000 / 4);
	}
	return (0);
}

static void	p_eating(t_philo *philos)
{
	int	time;

	pthread_mutex_lock(philos->l_fork);
	ft_message_print("has taken a fork", philos);
	pthread_mutex_lock(philos->r_fork);
	ft_message_print("has taken a fork", philos);
	time = get_current_time() - philos->start_time;
	pthread_mutex_lock(&philos->program->last_meal_lock);
	philos->last_meal = time;
	pthread_mutex_unlock(&philos->program->last_meal_lock);
	ft_message_print("is eating", philos);
	usleep(philos->program->time_to_eat * 1000);
	pthread_mutex_lock(&philos->program->meal_lock);
	philos->meals_eaten++;
	pthread_mutex_unlock(&philos->program->meal_lock);
	pthread_mutex_unlock(philos->r_fork);
	pthread_mutex_unlock(philos->l_fork);
}

void	*p_routine(void *p_pointer)
{
	t_philo	*philos;

	philos = (t_philo *)p_pointer;
	if (start_routine(philos) == 1)
		return (NULL);
	while (true)
	{
		if (philos->program->dead_flag == 1)
			break ;
		p_eating(philos);
		if (philos->program->num_times_to_eat != -1)
		{
			if (philos->meals_eaten >= philos->program->num_times_to_eat)
				break ;
		}
		ft_message_print("is sleeping", philos);
		usleep(philos->program->time_to_sleep * 1000);
		ft_message_print("is thinking", philos);
	}
	return (NULL);
}
