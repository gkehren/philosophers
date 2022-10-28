/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:32:00 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/28 18:07:42 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_param	*param)
{
	int	i;

	i = 0;
	while (i < param->nb_philo)
	{
		pthread_mutex_destroy(&(param->forks[i].mutex));
		i++;
	}
	pthread_mutex_destroy(&(param->writing.mutex));
	pthread_mutex_destroy(&(param->meal_check.mutex));
}

int	init_mutex(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philo)
	{
		param->forks[i].data = 0;
		if (pthread_mutex_init(&(param->forks[i].mutex), NULL))
			return (1);
		i++;
	}
	param->writing.data = 0;
	if (pthread_mutex_init(&(param->writing.mutex), NULL))
		return (1);
	param->meal_check.data = 0;
	if (pthread_mutex_init(&(param->meal_check.mutex), NULL))
		return (1);
	return (0);
}

int	init_philo(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philo)
	{
		param->philo[i].id = i;
		param->philo[i].check_eat = 0;
		param->philo[i].last_eat = 0;
		if (i == 0)
			param->philo[i].left_id = param->nb_philo - 1;
		else
			param->philo[i].left_id = i - 1;
		param->philo[i].right_id = (i + 1) % param->nb_philo;
		//param->philo[i].param = param;
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
		return (write(2, "Error: incorrect argument\n", 27), 1);
	if (argv[5])
	{
		param->nb_eat = ft_atoi(argv[5]);
		if (param->nb_eat <= 0)
			return (write(2, "Error: incorrect argument\n", 27), 1);
	}
	else
		param->nb_eat = -1;
	if (init_mutex(param))
		return (write(2, "Error: error when intializing mutex\n", 37), 1);
	init_philo(param);
	return (0);
}
