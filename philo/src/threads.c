/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:26:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:42:02 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_life(t_philo *philo)
{
	if (philo->philo_count == 1)
	{
		gettime(philo);
		printf("%ld %d has taken a fork\n", philo->start_time, philo->philo_id);
		printf("%ld %d is died\n", philo->t_die, philo->philo_id);
	}
	else
	{
		while (1)
		{
			take_fork(philo);
			ft_eat(philo);
			if (philo->eat_c == philo->max_eat)
				break ;
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	pthread_mutex_lock(philo->lock);
	*philo->is_full += 1;
	if (*philo->is_full == philo->philo_count)
		*philo->ph_dead = 1;
	pthread_mutex_unlock(philo->lock);
	return ;
}

void	create_thread(t_philo *philo, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_create(&philo[i].thread, NULL, (void *)philo_life, &philo[i]);
		pthread_detach(philo[i].thread);
		i++;
		usleep(200);
	}
}
