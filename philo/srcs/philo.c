/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 17:20:52 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philosopher(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->num_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (printf("Failed to create the thread\n"), exit(1));
		i++;
	}
	if (pthread_create(&philo->table->waiter.thread, NULL, is_spotless, philo))
		return (printf("Failed to create the thread\n"), exit(1));
	i = 0;
	while (i < philo->table->num_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(philo->table->waiter.thread, NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_table	table;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong number of arguments !\n", 29), 1);
	if (init(&philo, &table, argv) == 1)
		return (1);
	philosopher(philo);
	free(table.fork);
	free(philo);
	return (0);
}
