/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:50:07 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/22 13:52:56 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	mutex_handler(pthread_mutex_t *mtx, t_mtx_action act)
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

void	thread_handler(pthread_t *thread, void *(*routine)(void *),
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

long	getthetime(t_time time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		ft_error("Gettimeofday did not work as expected");
	if (time == SEC)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time == MLSEC)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time == MCROSEC)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		ft_error("Wrong input!! Try SEC, MILLISEC or MICROSEC.");
	return (42);
}

void	ft_usleep(long usec, t_table *table)
{
	long	start;
	long	time_passed;
	long	time_remained;

	start = getthetime(MCROSEC);
	while (getthetime(MCROSEC) - start < usec)
	{
		if (simulation_is_finished(table))
			break ;
		time_passed = getthetime(MCROSEC) - start;
		time_remained = usec - time_passed;
		if (time_remained > 1e3)
			usleep(usec / 2);
		else
		{
			while (getthetime(MCROSEC) - start < usec)
				;
		}
	}
}
