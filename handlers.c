/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:42:48 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/22 18:58:42 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	mutex_handler(pthread_mutex_t *mtx, t_mtx_action act)
{
	if (act == INIT)
	{
		if (pthread_mutex_init(mtx, NULL) != 0)
			ft_error("The valuse specified by attr is not valid\n");
	}
	else if (act == DESTROY)
	{
		if (pthread_mutex_destroy(mtx) != 0)
			ft_error("Mutex could not be destroyed\n");
	}
	else if (act == LOCK)
	{
		if (pthread_mutex_lock(mtx) != 0)
			ft_error("Mutex could not be locked\n");
	}
	else if (act == UNLOCK)
	{
		if (pthread_mutex_unlock(mtx) != 0)
			ft_error("Mutex could not be unlocked\n");
	}
	else
		ft_error("Wrong mutex action");
}

void	thread_handler(pthread_t *thread, void *(*routine)(void *),
		void *data, t_thread_action act)
{
	if (act == CREATE)
	{
		if (pthread_create(thread, NULL, routine, data) != 0)
			ft_error("Thread could not be created\n");
	}
	else if (act == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			ft_error("Thread could not be joined\n");
	}
	else if (act == DETACH)
	{
		if (pthread_detach(*thread) != 0)
			ft_error("Thread could not be detached\n");
	}
	else
		ft_error("Wrong thread action"
			"Use CREATE, JOIN or DETACH\n");
}
