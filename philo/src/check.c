/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:06:50 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 19:07:48 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong argument number!\n");
		return (0);
	}
	while (av[i])
	{
		if (!is_digit(av[i]) || ft_atoi(av[i]) <= 0)
		{
			printf("Wrong argument!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	dead_check(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->lock);
		if (*philo->ph_dead)
			return ;
		pthread_mutex_unlock(philo->lock);
	}
}
