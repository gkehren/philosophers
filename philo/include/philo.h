/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:59 by gkehren           #+#    #+#             */
/*   Updated: 2022/09/09 01:32:55 by gkehren          ###   ########.fr       */
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

typedef struct s_philo
{
	int				fork;
	int				check_eat;
	int				left_fork;
	int				right_fork;
	long long		last_eat;
	pthread_t		thread;
	struct s_param	*param;
}	t_philo;

typedef struct s_param
{
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					all_dead;
	int					all_eat;
	long long			first_time_stamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philo				philo[250];
}	t_param;

/*******UTILS*******/

int	ft_atoi(const char *str);
int	init(t_param *param, char **argv);

#endif
