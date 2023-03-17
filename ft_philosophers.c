/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:09:47 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/17 18:40:09 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (ac == 5 || ac == 6)
	{
		philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		if (arg_checker(ac, av) == 0)
			ft_error("Error\n");
		arg_converter(philo, ac, av);
		if (philo->nb_philo < 1)
			ft_error("Error\n");
		death = malloc(sizeof(pthread_mutex_t));
		forks = malloc(sizeof(pthread_mutex_t) * (philo->nb_philo));
		ft_init_philo(ac, philo);
	}
	else
		ft_error("Error\n");
	return (0);
}
