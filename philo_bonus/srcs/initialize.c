/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:53:27 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 21:34:05 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_create_semaphores(t_simulation *simulation)
{
	sem_unlink("death");
	sem_unlink("message");
	sem_unlink("stop");
	sem_unlink("forks");
	simulation->death = sem_open("death", O_CREAT, 0600, 1);
	simulation->message = sem_open("message", O_CREAT, 0600, 1);
	simulation->stop = sem_open("stop", O_CREAT, 0600, 1);
	simulation->forks = sem_open("forks", O_CREAT, 0600,
			simulation->philo_numbers);
}

void	ft_destroy_all(t_simulation *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < simulation->philo_numbers)
		kill(philo[i++].pid, SIGKILL);
	sem_close(simulation->death);
	sem_close(simulation->message);
	sem_close(simulation->stop);
	sem_close(simulation->forks);
	free(philo);
}

t_philo	*ft_philo_init(t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * simulation->philo_numbers);
	simulation->death = NULL;
	simulation->stop = NULL;
	simulation->message = NULL;
	simulation->forks = NULL;
	while (++i < simulation->philo_numbers)
		ft_for_each_philo(simulation, philo, i);
	return (philo);
}

void	ft_for_each_philo(t_simulation *simulation, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].is_dead = 0;
	philo[i].data = simulation;
	philo[i].pid = -1;
	if (simulation->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = simulation->eat_counter;
}

void	ft_print_message(int id, t_philo *philo)
{
	unsigned int	time;

	time = gettime() - philo->data->start;
	sem_wait(philo->data->message);
	if (id == 1)
		printf("%u\t%d has taken a left fork\n", time, philo->index + 1);
	else if (id == 7)
		printf("%u\t%d has taken a right fork\n", time, philo->index + 1);
	else if (id == 2)
		printf("%u\t%d is eating\n", time, philo->index + 1);
	else if (id == 3)
		printf("%u\t%d is sleeping\n", time, philo->index + 1);
	else if (id == 4)
		printf("%u\t%d is thinking\n", time, philo->index + 1);
	else if (id == 5)
		printf("%u\t%d died\n", time, philo->index + 1);
	if (id != 5)
		sem_post(philo->data->message);
}
