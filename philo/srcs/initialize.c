/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:05:09 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/16 21:47:20 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_mutex(t_pack *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.finish, NULL);
}

int	initialize(t_pack *p)
{
	int	i;

	i = 0;
	p->a.start_t = actual_time();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->a.total)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->a.start_t;
		p->ph[i].nb_eat = 0;
		p->ph[i].r_f = NULL;
		pthread_mutex_init(&p->ph[i].l_f, NULL);
		if (i == p->a.total - 1)
			p->ph[i].r_f = &p->ph[0].l_f;
		else
			p->ph[i].r_f = &p->ph[i + 1].l_f;
		i++;
	}
	return (0);
}
