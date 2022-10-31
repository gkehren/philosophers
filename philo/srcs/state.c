/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:15:48 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 11:41:28 by gkehren          ###   ########.fr       */
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

void	print_state(t_philo *philo)
{
	if (philo->status == HAS_TAKEN_A_FORK)
		printf("%ld %d has taken a fork\n",
			get_time_interval(philo->table->timer), philo->philo_num);
	else if (philo->status == EATING)
		printf("%ld %d is eating\n",
			get_time_interval(philo->table->timer), philo->philo_num);
	else if (philo->status == SLEEPING)
		printf("%ld %d is sleeping\n",
			get_time_interval(philo->table->timer), philo->philo_num);
	else if (philo->status == THINKING)
		printf("%ld %d is thinking\n",
			get_time_interval(philo->table->timer), philo->philo_num);
	else if (philo->status == DIED)
		printf("%ld %d died\n",
			get_time_interval(philo->table->timer), philo->philo_num);
}

void	set_state(t_philo *philo)
{
	if (philo->philo_num == 1)
		philo->status = EATING;
	else if (philo->philo_num == 2)
		philo->status = SLEEPING;
	else if (philo->philo_num == 3)
		philo->status = THINKING;
}
