/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:18:53 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:21:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	gettime(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	gettimeofday(&philo->tv, NULL);
	philo->ms = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (philo->start == 0)
		philo->start = philo->ms;
	philo->start_time = (philo->ms) - (philo->start);
	pthread_mutex_unlock(philo->lock);
}

void	ft_kill(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
	{
		printf("%ld %d is died\n", philo->start_time, philo->philo_id);
		*philo->ph_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

int	ft_usleep(t_philo *philo, long ms)
{
	long	time;

	gettime(philo);
	time = philo->start_time;
	while (philo->start_time < (ms + time))
	{
		gettime(philo);
		if (philo->start_time > philo->death)
		{
			ft_kill(philo);
			return (0);
		}
		usleep(100);
	}
	return (1);
}

int	ft_atoi(char *num)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10 + (num[i] - '0');
		i++;
	}
	return (res);
}

int	is_digit(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < '0' || arr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
