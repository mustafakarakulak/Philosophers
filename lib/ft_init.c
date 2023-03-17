/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:24:21 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/17 20:22:47 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_init_philo(int ac, t_philo *philo)
{
	printf("%d\n", ac);
	printf("%d     %d     %d     %d     %d\n", philo->nb_philo, philo->time_die,
		philo->time_eat, philo->time_sleep, philo->nb_eat);
}
