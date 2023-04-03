/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:09:47 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/03 18:19:00 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo			*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		if (arg_checker(ac, av) == 0)
		{
			ft_error("Error\n");
			return (1);
		}
		if (arg_converter(data, ac, av) == 1)
			return (1);
		death = malloc(sizeof(pthread_mutex_t));
		forks = malloc(sizeof(pthread_mutex_t) * (data->nb_philo));
		ft_init_philo(ac, data);
	}
	else
		ft_error("Error\n");
	return (0);
}
