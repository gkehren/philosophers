/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:03:34 by gkehren           #+#    #+#             */
/*   Updated: 2022/11/07 01:46:25 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_table *table, long last_meal)
{
	if (get_time_interval(last_meal) > table->time_to_die)
		return (0);
	return (1);
}

void	*waiter(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (!philo->table->waiter.close_the_place)
	{
		i = -1;
		while (++i < philo->table->num_of_philos && \
		!philo->table->waiter.close_the_place)
		{
			if (!is_dead(philo->table, philo[i].last_meal))
				print_state(&philo[i], DIED);
			if (!(philo->table->waiter.table_capacity) && \
			philo->table->times_must_eat)
				philo->table->waiter.close_the_place = 1;
		}
		usleep(700);
	}
	return (NULL);
}
