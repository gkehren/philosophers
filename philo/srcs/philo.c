/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 11:42:24 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	int			state;
	t_philo		*philo;

	philo = arg;
	state = philo->status;
	set_state(philo);
	printf("id [%d] state [%d]\n", philo->philo_num, philo->status);
	if (philo->status != state)
		print_state(philo);
	pthread_exit(EXIT_SUCCESS);
}

void	philosopher(t_philo *philo)
{
	int	err;
	int	i;

	i = 0;
	printf("---------- Avant ----------\n");
	while (i < philo->table->num_of_philos)
	{
		err = pthread_create(&philo->thread, NULL, routine, &philo[i]);
		if (err != 0)
			return (printf("Failed to create the thread: [%s]",
					strerror(err)), exit(1));
		i++;
	}
	i = 0;
	while (i < philo->table->num_of_philos)
	{
		pthread_join(philo->thread, NULL);
		i++;
	}
	printf("---------- Après ----------\n");
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
	return (0);
}
