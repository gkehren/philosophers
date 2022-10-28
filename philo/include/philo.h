/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:59 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/28 18:18:17 by gkehren          ###   ########.fr       */
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

// pour les fourchettes forks[250] cela signifie que il faut aller de 0 à nb_forks
// puis check si forks.data == 0
// si forks.data == 0 alors fourchette est dispo
// sinon forks.data == 1 et elle n'est pas dispo donc le philo ne peut pas manger

// Ordre des actions : manger -> dormir -> penser

// Dans le cas ou il y aurait 3 philo
// philo[0] = manger
// philo[1] = penser (car il ne peut pas manger, la fourchette est utilisé par philo[0])


typedef struct s_mutex_data {
	int data;
	pthread_mutex_t mutex;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	int				check_eat;
	int				left_id;
	int				right_id;
	long long		last_eat;
	pthread_t		thread;
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
	t_mutex				meal_check;
	t_mutex				forks[250];
	t_mutex				writing;
	t_philo				philo[250];
}	t_param;

/*******UTILS*******/

int		ft_atoi(const char *str);
int		init(t_param *param, char **argv);
void	destroy_mutex(t_param	*param);

#endif
