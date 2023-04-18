/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:10:27 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:13:34 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_count)
		pthread_mutex_destroy(&philo->mutex[i++]);
	pthread_mutex_destroy(philo->lock);
	free(philo->mutex);
	free(philo->lock);
	free(philo->is_full);
	free(philo->ph_dead);
	free(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		size;

	if (!check_arg(ac, av))
		return (1);
	size = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * size);
	set_mutex(philo, size);
	init_philo(philo, av, size);
	create_thread(philo, size);
	dead_check(philo);
	if (philo->max_eat_count != -1)
		printf("Philosophers ate %d of meal(s) in total and died.\n",
			philo->eat_c);
	ft_free(philo);
	return (0);
}
