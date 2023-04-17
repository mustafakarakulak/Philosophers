/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:05:12 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/17 05:40:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_death2(t_pack *p)
{
	pthread_mutex_lock(&p->a.dead);
	if (p->a.stop)
	{
		pthread_mutex_unlock(&p->a.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->a.dead);
	return (0);
}

void	philo(t_pack *p)
{
	int	i;

	i = -1;
	while (check_death2(p))
		ft_usleep(1);
	while (++i < p->a.total)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->a.write_mutex);
	i = -1;
	while (++i < p->a.total)
		pthread_mutex_destroy(&p->ph[i].l_f);
	if (p->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->a.m_eat);
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_pack		*data;

	data = malloc(sizeof(t_pack));
	if (parse_args(argc, argv, data))
		return (ft_exit("Invalid Arguments\n"));
	data->ph = malloc(sizeof(t_philo) * data->a.total);
	if (!data->ph)
		return (ft_exit("Malloc returned NULL\n"));
	if (initialize(data) || threading(data))
	{
		free(data->ph);
		return (0);
	}
	philo(data);
	free(data);
}
