/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/08/04 17:13:07 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*fn_table(void	*p_data)
{
	while (1)
	{
		/* beginning of the protected area */
		pthread_mutex_lock(&store.mutex_fork);
		if (store.fork <= 0)
		{
			store.fork = INITIAL_FORK;
			printf("fill table with %d fork!\n", store.fork);
		}
		/* ending of the protected area */
		pthread_mutex_unlock(&store.mutex_fork);
	}
	(void)p_data;
	return (NULL);
}

void	init(t_philo *philo, int argc, char **argv)
{
	//int	i;
	int	ret;

	(void)argc;
	philo->philos = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	printf("Threading table...\n");
	ret = pthread_create(&philo->table, NULL, fn_table, NULL);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	init(&philo, argc, argv);
	return (0);
}
