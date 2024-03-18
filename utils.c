/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:50:07 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/18 17:47:37 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	mutex_hander(pthread_mutex_t mtx, t_mtx_action act)
{
	if (act == INIT)
	{
		if (pthread_mutex_init(&mtx, NULL) != 0)
			ft_error("Mutex could not be created");
	}
	else if (act == DESTROY)
	{
		if (pthread_mutex_destroy(&mtx) != 0)
			ft_error("Mutex could not be destroyed");
	}
	else if (act == LOCK)
	{
		if (pthread_mutex_lock(&mtx) != 0)
			ft_error("Mutex could not be locked");
	}
	else if (act == UNLOCK)
	{
		if (pthread_mutex_unlock(&mtx) != 0)
			ft_error("Mutex could not be unlocked");
	}
	else
		ft_error("Wrong mutex action");
}

// void	thread_hander(pthread_ mtx, t_mtx_action act)
// {
// 	if (act == INIT)
// 	{
// 		if (pthread_mutex_init(&mtx, NULL) != 0)
// 			ft_error("Mutex could not be created");
// 	}
// 	else if (act == DESTROY)
// 	{
// 		if (pthread_mutex_destroy(&mtx) != 0)
// 			ft_error("Mutex could not be destroyed");
// 	}
// 	else if (act == LOCK)
// 	{
// 		if (pthread_mutex_lock(&mtx) != 0)
// 			ft_error("Mutex could not be locked");
// 	}
// 	else if (act == UNLOCK)
// 	{
// 		if (pthread_mutex_unlock(&mtx) != 0)
// 			ft_error("Mutex could not be unlocked");
// 	}
// 	else
// 		ft_error("Wrong mutex action");
// }