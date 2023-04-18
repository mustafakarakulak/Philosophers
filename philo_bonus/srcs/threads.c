/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:35:46 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:40:19 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_routine(t_philo *philo)
{
	pthread_t	death;

	philo->next_meal = ft_get_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_print_message(4, philo);
	}
}

void	ft_create_process(t_simulation *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < simulation->philo_numbers)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(philo + i);
			exit(0);
		}
		i++;
		usleep(200);
	}
}
