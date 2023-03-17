/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:10:54 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/17 18:41:56 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id_philo;
	int			nb_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			nb_eat;
	pthread_t	thread;
}	t_philo;

void	arg_converter(t_philo *philo, int ac, char **av);
void	ft_init_philo(int ac, t_philo *philo);
int		arg_checker(int ac, char **av);

void	ft_error(char *str);
int		ft_free(t_philo *data);
int		ft_atoi(char *str);

#endif