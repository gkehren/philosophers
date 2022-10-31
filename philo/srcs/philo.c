/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/10/31 10:55:36 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_philo(t_philo **philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		printf("Philo n°%d\n", (*philo)[i].philo_num);
		i++;
	}
}

//void	*routine(void *arg)
//{
//	t_philo		*philo;
//	int			state;

//	philo = arg;
//	state = philo->state;
//	set_state(philo);
//	printf("id [%d] state [%d]\n", philo->id, philo->state);
//	if (philo->state != state)
//		print_state(philo);
//	pthread_exit(EXIT_SUCCESS);
//}

//void	philosopher(t_param *param)
//{
//	void		*ret;
//	int			err;
//	int			i;

//	i = 0;
//	printf("---------- Avant ----------\n");
//	while (i < param->nb_philo)
//	{
//		err = pthread_create(&param->philo[i].thread, NULL, routine, &param->philo[i]);
//		if (err != 0)
//			return (printf("Failed to create the thread: [%s]", strerror(err)), exit(1));
//		i++;
//	}
//	i = 0;
//	while (i < param->nb_philo)
//	{
//		pthread_join(param->philo[i].thread, &ret);
//		printf("return value: %ld\n", (long)ret);
//		i++;
//	}
//	printf("---------- Après ----------\n");
//}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_table table;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong number of arguments !\n", 29), 1);
	if (init(&philo, &table, argv) == 1)
		return (1);
	print_philo(&philo, &table);
	//philosopher(&param);
	return (0);
}
