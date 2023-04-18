/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:53:55 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:44:40 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned int	gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print_message(1, philo);
	sem_wait(philo->data->forks);
	ft_print_message(7, philo);
}

void	ft_eat(t_philo *philo)
{
	ft_print_message(2, philo);
	if (philo->data->eat_counter != -1)
		philo->data->current_eat++;
	usleep(philo->data->time_to_eat * 1000);
	philo->eating_time = gettime();
	philo->next_meal = philo->eating_time
		+ (unsigned int)philo->data->time_to_die;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_message(3, philo);
	usleep(philo->data->time_to_sleep * 1000);
}
