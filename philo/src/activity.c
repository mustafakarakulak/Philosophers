/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:10:25 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:32:50 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_fork(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
	{
		printf("%ld %d has taken a left fork\n",
			philo->start_time, philo->philo_id);
		printf("%ld %d has taken a right fork\n",
			philo->start_time, philo->philo_id);
	}
	pthread_mutex_unlock(philo->lock);
}

void	ft_eat(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
		printf("%ld %d is eating\n", philo->start_time, philo->philo_id);
	pthread_mutex_unlock(philo->lock);
	philo->eat_c++;
	ft_usleep(philo, philo->t_eat);
	philo->death = philo->start_time + philo->t_die;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	ft_sleep(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
		printf("%ld %d is sleeping\n", philo->start_time, philo->philo_id);
	pthread_mutex_unlock(philo->lock);
	ft_usleep(philo, philo->t_sleep);
}

void	ft_think(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
		printf("%ld %d is thinking\n", philo->start_time, philo->philo_id);
	pthread_mutex_unlock(philo->lock);
}
