/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:42:48 by stigkas           #+#    #+#             */
/*   Updated: 2024/04/02 16:53:45 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	mtx_error(int mtx_err, t_mtx_action act)
{
	if (mtx_err != 0 && act == INIT)
	{
		printf("The values specified by attr are not valid\n");
		return (0);
	}
	else if (mtx_err != 0 && act == DESTROY)
	{
		printf("Mutex could not be destroyed\n");
		return (0);
	}
	else if (mtx_err != 0 && act == LOCK)
	{
		printf("Mutex could not be locked\n");
		return (0);
	}
	else if (mtx_err != 0 && act == UNLOCK)
	{
		printf("Mutex could not be unlocked\n");
		return (0);
	}
	return (1);
}

int	mtx_handler(pthread_mutex_t *mtx, t_mtx_action act)
{
	if (act == INIT)
	{
		if (!mtx_error(pthread_mutex_init(mtx, NULL), INIT))
			return (0);
	}
	else if (act == DESTROY)
	{
		if (!mtx_error(pthread_mutex_destroy(mtx), DESTROY))
			return (0);
	}
	else if (act == LOCK)
	{
		if (!mtx_error(pthread_mutex_lock(mtx), LOCK))
			return (0);
	}
	else if (act == UNLOCK)
	{
		if (pthread_mutex_unlock(mtx) != 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	th_error(int thread_err, t_thread_action act)
{
	if (thread_err != 0 && act == CREATE)
	{
		printf("Thread could not be created\n");
		return (0);
	}
	else if (thread_err != 0 && act == JOIN)
	{
		printf("Thread could not be joined\n");
		return (0);
	}
	else if (thread_err != 0 && act == DETACH)
	{
		printf("Thread could not be detached\n");
		return (0);
	}
	return (1);
}

int	thread_handler(pthread_t *thread, void *(*routine)(void *),
		void *data, t_thread_action act)
{
	if (act == CREATE)
	{
		if (!th_error(pthread_create(thread, NULL, routine, data), CREATE))
			return (0);
	}
	else if (act == JOIN)
	{
		if (!th_error(pthread_join(*thread, NULL), JOIN))
			return (0);
	}
	else if (act == DETACH)
	{
		if (!th_error(pthread_detach(*thread), DETACH))
			return (0);
	}
	else
	{
		printf("Wrong thread action"
			"Use CREATE, JOIN or DETACH\n");
		return (0);
	}
	return (1);
}
