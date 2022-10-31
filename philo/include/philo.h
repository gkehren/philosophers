/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:59 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 10:51:16 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*******INCLUDE*******/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/*******STRUCT*******/

enum e_state {
	EATING,
	SLEEPING,
	THINKING,
	HAS_TAKEN_A_FORK,
	DIED
};

typedef struct s_waiter
{
	pthread_t	thread;
	int			sink_capacity;
	int			close_the_place;
}				t_waiter;

typedef struct s_table
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	meals_count_access;
	pthread_mutex_t	microphone;
	t_waiter		waiter;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	long			timer;
}				t_table;

typedef struct s_philo
{
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*right_hand;
	int				philo_num;
	int				meals_count;
	int				status;
	long			last_meal;
}				t_philo;

/*******STATE*******/

void	print_state(t_philo *philo);
void	set_state(t_philo *philo);

/*******TIME*******/

long	get_timestamp(void);

/*******UTILS*******/

int		ft_atoi(const char *str);
int		init(t_philo **philo, t_table *table, char **argv);

#endif
