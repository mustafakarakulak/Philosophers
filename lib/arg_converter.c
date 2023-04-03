/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:32:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/03 18:18:02 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	arg_converter2(t_philo *data)
{
	if (data->nb_philo <= 0 || data->nb_philo > 200 || data->time_die <= 0
		|| data->time_eat <= 0 || data->time_sleep <= 0)
	{
		ft_error("Error\n");
		return (1);
	}
	return (0);
}

int	arg_converter(t_philo *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_eat = ft_atoi(av[5]);
	else
		data->nb_eat = -1;
	if (arg_converter2(data) == 1)
		return (1);
	return (0);
}
