/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/09/09 13:40:30 by gkehren          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong number of arguments !\n", 29), 1);
	if (init(&param, argv) == 1)
		return (1);
	return (0);
}
