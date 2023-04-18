/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:10:31 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/18 20:41:53 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_philo
{
	struct timeval	tv;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	unsigned long	t_eat;
	unsigned long	t_die;
	unsigned long	t_sleep;
	unsigned long	last_meal;
	pthread_t		thread;
	long			start_time;
	long			death;
	long			ms;
	long			start;
	int				philo_id;
	int				philo_count;
	int				eat_c;
	int				*ph_dead;
	int				*is_full;
	int				max_eat;
}					t_philo;

int		is_digit(char *arr);
int		check_arg(int ac, char **av);
void	dead_check(t_philo *philo);
void	init_philo(t_philo *philo, char **av, int size);
void	set_basic(t_philo *philo, char **av);
void	set_mutex(t_philo *philo, int size);
void	create_thread(t_philo *philo, int philo_count);
void	gettime(t_philo *philo);
void	take_fork(t_philo *philo);
int		ft_usleep(t_philo *philo, long ms);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
int		ft_atoi(char *s);
void	ft_kill(t_philo *philo);

#endif