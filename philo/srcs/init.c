/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:32:00 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 11:06:33 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->num_of_philos);
	if (!table->fork)
		return (write(2, "Error: malloc error\n", 27), 1);
	while (i < table->num_of_philos)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&(table->meals_count_access), NULL);
	pthread_mutex_init(&(table->microphone), NULL);
	return (0);
}

static int	init_philo(t_philo **philo, t_table *table)
{
	int	i;

	i = 0;
	(*philo) = malloc(sizeof(t_philo) * table->num_of_philos);
	if ((!*philo))
		return (write(2, "Error: malloc error\n", 27), 1);
	while (i < table->num_of_philos)
	{
		(*philo)[i].table = table;
		(*philo)[i].philo_num = i + 1;
		(*philo)[i].left_hand = &table->fork[i];
		if (i == (table->num_of_philos - 1))
			(*philo)[i].right_hand = &table->fork[0];
		else
			(*philo)[i].right_hand = &table->fork[i + 1];
		(*philo)[i].meals_count = 0;
		(*philo)[i].last_meal = table->timer;
		i++;
	}
	return (0);
}

static int	init_table(t_table *table, char **argv)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (table->num_of_philos < 2 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0)
		return (write(2, "Error: incorrect argument\n", 27), 1);
	if (argv[5])
	{
		table->times_must_eat = ft_atoi(argv[5]);
		if (table->times_must_eat <= 0)
			return (write(2, "Error: incorrect argument\n", 27), 1);
	}
	else
		table->times_must_eat = -1;
	table->waiter.close_the_place = 0;
	table->waiter.sink_capacity = table->num_of_philos * table->times_must_eat;
	table->timer = get_timestamp();
	return (0);
}

int	init(t_philo **philo, t_table *table, char **argv)
{
	if (init_table(table, argv) == 1)
		return (1);
	if (init_mutex(table))
		return (1);
	if (init_philo(philo, table) == 1)
		return (free(table->fork), 1);
	return (0);
}
