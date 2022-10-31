/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:15:48 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 10:56:23 by gkehren          ###   ########.fr       */
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

//void	print_state(t_philo *philo)
//{
//	if (philo->state == HAS_TAKEN_A_FORK)
//		printf("%ld %d has taken a fork\n", get_timestamp(), philo->id + 1);
//	else if (philo->state == EATING)
//		printf("%ld %d is eating\n", get_timestamp(), philo->id + 1);
//	else if (philo->state == SLEEPING)
//		printf("%ld %d is sleeping\n", get_timestamp(), philo->id + 1);
//	else if (philo->state == THINKING)
//		printf("%ld %d is thinking\n", get_timestamp(), philo->id + 1);
//	else if (philo->state == DIED)
//		printf("%ld %d died\n", get_timestamp(), philo->id + 1);
//}

//void	set_state(t_philo *philo)
//{
//	if (philo->id == 0)
//		philo->state = EATING;
//	else if (philo->id == 1)
//		philo->state = SLEEPING;
//	else if (philo->id == 2)
//		philo->state = THINKING;
//}
