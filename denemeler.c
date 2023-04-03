/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   denemeler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:32:38 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/03 17:25:08 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*thread function definition*/
void	*threadfunction(void *args)
{
	while (1)
	{
		sleep(1);
		printf("I am threadFunction.\n");
	}
}

/*creating thread id*/
int	main(void)
{
	pthread_t	*id;
	int			ret;

	ret = pthread_create(id, NULL, threadfunction, NULL);
	if (ret == 0)
	{
		printf("Thread created successfully.\n");
	}
	else
	{
		printf("Thread not created.\n");
		return (0);
	}
	while (1)
	{
		sleep(1);
		printf("I am main function.\n");
	}
	return (0);
}
