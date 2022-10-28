/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/28 18:09:32 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_philo(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philo)
	{
		printf("Philo n°%d\n", i);
		printf("ID: %d\n", param->philo[i].id);
		printf("LEFT ID: %d\n", param->philo[i].left_id);
		printf("RIGHT ID: %d\n\n", param->philo[i].right_id);
		i++;
	}
}

void	*routine(void *arg)
{
	pthread_t	tid;
	t_param		*param;

	param = arg;
	tid = pthread_self();
	printf("thread [%ld] forks [%d]\n", (long)tid, param->writing.data);
	param->writing.data++;
	pthread_exit(EXIT_SUCCESS);
}

void	philosopher(t_param *param)
{
	void		*ret;
	int			err;
	int			i;

	i = 0;
	printf("---------- Avant ----------\n");
	while (i < param->nb_philo)
	{
		err = pthread_create(&param->philo[i].thread, NULL, routine, param);
		if (err != 0)
			return (printf("Failed to create the thread: [%s]", strerror(err)), exit(1));
		i++;
	}
	i = 0;
	while (i < param->nb_philo)
	{
		pthread_join(param->philo[i].thread, &ret);
		printf("return value: %ld\n", (long)ret);
		i++;
	}
	printf("---------- Après ----------\n");
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong number of arguments !\n", 29), 1);
	if (init(&param, argv) == 1)
		return (1);
	//print_philo(&param);
	philosopher(&param);
	destroy_mutex(&param);
	return (0);
}
