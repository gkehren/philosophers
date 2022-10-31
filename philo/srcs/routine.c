/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:18:33 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 17:19:54 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_in_the_sink(t_philo *philo)
{
	if (!philo->table->waiter.close_the_place)
	{
		pthread_mutex_lock(&(philo->table->meals_count_access));
		(philo->meals_count)++;
		if (philo->meals_count <= philo->table->times_must_eat)
			(philo->table->waiter.sink_capacity)--;
		pthread_mutex_unlock(&(philo->table->meals_count_access));
	}
}

void	*devour(t_philo *philo)
{
	pthread_mutex_lock(philo->left_hand);
	print_state(philo, HAS_TAKEN_A_FORK);
	pthread_mutex_lock(philo->right_hand);
	print_state(philo, HAS_TAKEN_A_FORK);
	print_state(philo, EATING);
	put_in_the_sink(philo);
	usleep((philo->table->time_to_eat * 1000));
	return (NULL);
}

void	*take_a_nap(t_philo *philo)
{
	print_state(philo, SLEEPING);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
	usleep(philo->table->time_to_sleep * 1000);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	while (!philo->table->waiter.close_the_place)
	{
		if (philo->philo_num % 2 == 0)
			usleep(300);
		if (philo->table->num_of_philos == 1)
		{
			pthread_mutex_lock(philo->left_hand);
			print_state(philo, HAS_TAKEN_A_FORK);
			pthread_mutex_unlock(philo->left_hand);
			break ;
		}
		devour(philo);
		take_a_nap(philo);
		print_state(philo, THINKING);
	}
	pthread_exit(EXIT_SUCCESS);
}
