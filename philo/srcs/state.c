/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:15:48 by gkehren           #+#    #+#             */
/*   Updated: 2022/11/08 14:08:40 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_timestamp(void)
{
	struct timeval	current_time;
	long			time_stamp;

	gettimeofday(&current_time, NULL);
	time_stamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time_stamp);
}

long	get_time_interval(long old_timestamp)
{
	struct timeval	current_time;
	long			timestamp;
	long			time_interval;

	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	time_interval = timestamp - old_timestamp;
	return (time_interval);
}

void	print_state(t_philo *philo, int status)
{
	long	time;

	pthread_mutex_lock(&(philo->table->microphone));
	time = get_time_interval(philo->table->timer);
	if (status == DIED && !philo->table->waiter.close_the_place)
	{
		philo->table->waiter.close_the_place = 1;
		printf("\033[31m%ld\t%d died\n\033[00m", time, philo->philo_num);
	}
	if (!philo->table->waiter.close_the_place)
	{
		if (status == EATING)
		{
			philo->last_meal = get_timestamp();
			printf("\033[32m%ld\t%d is eating\n\033[00m", time, philo->philo_num);
		}
		else if (status == SLEEPING)
			printf("\033[35m%ld\t%d is sleeping\n\033[00m", time, philo->philo_num);
		else if (status == THINKING)
			printf("\033[34m%ld\t%d is thinking\n\033[00m", time, philo->philo_num);
		else if (status == HAS_TAKEN_A_FORK)
			printf("\033[33m%ld\t%d has taken a fork\n\033[00m", time, \
			philo->philo_num);
	}
	pthread_mutex_unlock(&(philo->table->microphone));
}
