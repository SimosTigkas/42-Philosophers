/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:41:11 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/14 14:06:35 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*send_value(void)
{
	int	value;
	int	*result;

	value = 42;
	result = malloc(sizeof(int));
	*result = value;
	printf("Thread result: %p\n", result);
	return ((void *) result);
}

int	main(void)
{
	int			*res;
	pthread_t	t1;

	if (pthread_create(&t1, NULL, &send_value, NULL) != 0)
		return (1);
	if (pthread_join(t1, (void **) &res) != 0)
		return (2);
	printf("Main res: %p\n", res);
	printf("Result: %d\n", *res);
	free(res);
	return (0);
}
