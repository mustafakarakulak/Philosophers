/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:01:28 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 21:25:27 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;
	t_simulation	*simulation;

	i = 0;
	simulation = malloc(sizeof(t_simulation));
	if (ac == 5 || ac == 6)
	{
		if (ft_parsing(av, simulation))
			return (1);
		philo = ft_philo_init(simulation);
		simulation->start = gettime();
		ft_create_semaphores(simulation);
		sem_wait(simulation->stop);
		ft_create_process(simulation, philo);
		sem_wait(simulation->stop);
		ft_destroy_all(simulation, philo);
	}
	else
		printf("Error: Too many arguments\n");
	return (0);
}
