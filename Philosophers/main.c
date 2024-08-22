/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:16:16 by ankupins          #+#    #+#             */
/*   Updated: 2024/06/14 12:16:20 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[201];
	pthread_mutex_t	forks[201];

	if (argc != 5 && argc != 6)
	{
		f_wrong_argv_exit();
		return (2);
	}
	else
	{
		if (input_check(argc, argv, &program) == -1)
			return (2);
	}
	init_philos(philos, &program, forks);
	init_forks(forks, program.num_of_philos);
	if (start_party(&program) == -1)
		return (2);
	after_party_clean(&program, forks);
	return (0);
}
