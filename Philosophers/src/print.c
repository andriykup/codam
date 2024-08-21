/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:30:25 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/13 19:30:26 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_message_print(char *message, t_philo *philos)
{
	int	time;

	time = get_current_time() - philos->start_time;
	pthread_mutex_lock(&philos->program->write_lock);
	if (philos->program->write_flag_lock == 0)
		printf("%d %d %s\n", time, philos->id, message);
	pthread_mutex_unlock(&philos->program->write_lock);
}
