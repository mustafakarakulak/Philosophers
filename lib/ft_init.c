/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:24:21 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/17 22:38:51 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_init_philo(int ac, t_philo *data)
{
	printf("%d\n", ac);
	printf("%d     %d     %d     %d     %d\n", data->nb_philo, data->time_die,
		data->time_eat, data->time_sleep, data->nb_eat);


}
