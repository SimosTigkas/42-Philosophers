/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:39:19 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/13 13:54:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*routine(void)
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
