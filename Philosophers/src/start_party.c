/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_party.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:29 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/02 15:41:31 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*monitoring(void *pointer)
{
	t_program	*program;

	program = (t_program *)pointer;
	if (program->num_of_philos == 1)
		return (NULL);
	while (true)
	{
		if (check_times_to_eat(program) == 1)
		{
			pthread_mutex_lock(&program->dead_lock);
			pthread_mutex_lock(&program->write_lock);
			program->dead_flag = 1;
			program->write_flag_lock = 1;
			pthread_mutex_unlock(&program->write_lock);
			pthread_mutex_unlock(&program->dead_lock);
			break ;
		}
		if (check_dead(program) == 1)
			break ;
	}
	return (NULL);
}

int	start_party(t_program *program)
{
	int			i;
	pthread_t	observer;

	if (pthread_create(&observer, NULL, &monitoring, (void *)program) != 0)
		return (-1);
	i = 0;
	while (i < program->num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL,
				&p_routine, &program->philos[i]) != 0)
			return (-1);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		return (-1);
	i = 0;
	while (i < program->num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}
