/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:50:07 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/19 18:44:57 by marvin           ###   ########.fr       */
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

void	thread_hander(pthread_t *thread, void *(*routine)(void *),
		void *data, t_thread_action act)
{
	if (act == CREATE)
	{
		if (pthread_create(thread, NULL, routine, data) != 0)
			ft_error("Thread could not be created..");
	}
	else if (act == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			ft_error("Thread could not be joined..");
	}
	else if (act == DETACH)
	{
		if (pthread_detach(*thread) != 0)
			ft_error("Thread could not be detached");
	}
	else
	{
		ft_error("Wrong thread action");
		ft_error("Use CREATE, JOIN or DETACH");
	}
}