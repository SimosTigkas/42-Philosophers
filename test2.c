/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:13:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/14 14:49:26 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*prime(void *arg)
{
	int	index;

	index = *(int *)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int	main(void)
{
	pthread_t	t[10];
	int			i;
	int			*a;

	while (i < 10)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&t[i], NULL, &prime, a) != 0)
			perror("Failed to create the thread");
		free(a);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(t[i], NULL) != 0)
			perror("Failed to join the thread");
		i++;
	}
	return (0);
}
