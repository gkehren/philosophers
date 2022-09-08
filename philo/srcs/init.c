/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:32:00 by gkehren           #+#    #+#             */
/*   Updated: 2022/09/09 01:49:17 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* 250 is the fork limit (see ulimit -u) */

int	init_mutex(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philo)
	{
		if (pthread_mutex_init(&(param->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(param->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(param->meal_check), NULL))
		return (1);
	return (0);
}

int	init_philo(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philo)
	{
		param->philo[i].fork = i;
		param->philo[i].check_eat = 0;
		param->philo[i].last_eat = 0;
		if (i == 0)
			param->philo[i].left_fork = param->nb_philo - 1;
		else
			param->philo[i].left_fork = i - 1;
		param->philo[i].right_fork = (i + 1) % param->nb_philo;
		param->philo[i].param = param;
		i++;
	}
	return (0);
}

int	init(t_param *param, char **argv)
{
	param->nb_philo = ft_atoi(argv[1]);
	param->time_die = ft_atoi(argv[2]);
	param->time_die = ft_atoi(argv[3]);
	param->time_sleep = ft_atoi(argv[4]);
	param->all_dead = 0;
	param->all_eat = 0;
	if (param->nb_philo < 2 || param->time_die < 0 || param->time_eat < 0
		|| param->time_sleep < 0 || param->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		param->nb_eat = ft_atoi(argv[5]);
		if (param->nb_eat <= 0)
			return (1);
	}
	else
		param->nb_eat = -1;
	if (init_mutex(param))
		return (2);
	init_philo(param);
	return (0);
}
