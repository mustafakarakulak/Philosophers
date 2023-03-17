/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:32:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/17 18:42:05 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	arg_converter(t_philo *philo, int ac, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_die = ft_atoi(av[2]);
	philo->time_eat = ft_atoi(av[3]);
	philo->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_eat = ft_atoi(av[5]);
	else
		philo->nb_eat = -1;
}
