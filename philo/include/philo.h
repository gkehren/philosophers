/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:59 by gkehren           #+#    #+#             */
/*   Updated: 2022/08/04 17:17:33 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*******INCLUDE*******/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

/*******DEFINE*******/
// this define will be change to the initial number_of_philosophers
# define INITIAL_FORK	0

/*******STRUCT*******/

typedef struct s_philo
{
	int				fork;
	pthread_mutex_t	mutex_fork;
	pthread_t		table;
	pthread_t		*philos;
}	t_philo;

static t_philo store =
{
	.fork = INITIAL_FORK,
	.mutex_fork = PTHREAD_MUTEX_INITIALIZER,
};

/*******UTILS*******/

int	ft_atoi(const char *str);

#endif
