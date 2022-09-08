/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/09/09 01:57:23 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//void	print_philo(t_param *param)
//{
//	int	i;

//	i = 0;
//	while (i < param->nb_philo)
//	{
//		printf("Philo n°%d\n", i);
//		printf("ID: %d\n", param->philo[i].fork);
//		printf("LEFT ID: %d\n", param->philo[i].left_fork);
//		printf("RIGHT ID: %d\n\n", param->philo[i].right_fork);
//		i++;
//	}
//}

int	manage_error(int error)
{
	if (error == 1)
		return (write(2, "Error: incorrect argument\n", 27), 1);
	if (error == 2)
		return (write(2, "Error: error when intializing mutex\n", 27), 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	param;
	int		error;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong number of arguments !\n", 29), 1);
	if ((error = init(&param, argv)))
		return (manage_error(error));
	return (0);
}
