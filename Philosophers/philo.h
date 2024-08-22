/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:17:19 by ankupins          #+#    #+#             */
/*   Updated: 2024/06/14 12:17:21 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_program;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					eating;
	int					meals_eaten;
	int					last_meal;
	int					start_time;
	int					*dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	struct s_program	*program;
}					t_philo;

typedef struct s_program
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_to_eat;
	int				dead_flag;
	int				write_flag_lock;
	pthread_mutex_t	last_meal_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}					t_program;

int		start_party(t_program *program);
void	*p_routine(void *p_pointer);

//checks + parsing
int		input_check(int argc, char **argv, t_program *program);
int		check_dead(t_program *program);
int		check_times_to_eat(t_program *program);

//init
void	init_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks);
void	init_forks(pthread_mutex_t *forks, int philo_num);

//utils
int		ft_strlen(char *str);
int		get_current_time(void);

//exit & clean & print
void	ft_message_print(char *message, t_philo *philos);
int		f_wrong_value_exit(void);
int		f_wrong_argv_exit(void);
void	after_party_clean(t_program *program, pthread_mutex_t *forks);

#endif
