/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:50:07 by stigkas           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/22 13:52:56 by stigkas          ###   ########.fr       */
=======
/*   Updated: 2024/03/21 13:20:46 by marvin           ###   ########.fr       */
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
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

<<<<<<< HEAD
void	thread_handler(pthread_t *thread, void *(*routine)(void *),
=======
void	thread_hander(pthread_t *thread, void *(*routine)(void *),
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
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

<<<<<<< HEAD
long	getthetime(t_time time)
=======
long get_time_of_day(t_time time)
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		ft_error("Gettimeofday did not work as expected");
	if (time == SEC)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
<<<<<<< HEAD
	else if (time == MLSEC)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time == MCROSEC)
=======
	else if (time == MILLISEC)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time == MICROSEC)
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		ft_error("Wrong input!! Try SEC, MILLISEC or MICROSEC.");
	return (42);
}

<<<<<<< HEAD
void	ft_usleep(long usec, t_table *table)
=======
void ft_usleep(long usec, t_table *table)
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
{
	long	start;
	long	time_passed;
	long	time_remained;

<<<<<<< HEAD
	start = getthetime(MCROSEC);
	while (getthetime(MCROSEC) - start < usec)
	{
		if (simulation_is_finished(table))
			break ;
		time_passed = getthetime(MCROSEC) - start;
=======
	start = get_time_of_day(MICROSEC);
	while (get_time_of_day(MICROSEC) - start < usec)
	{
		if (simulation_is_finished(table))
			break ;
		time_passed = get_time_of_day(MICROSEC) - start;
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
		time_remained = usec - time_passed;
		if (time_remained > 1e3)
			usleep(usec / 2);
		else
		{
<<<<<<< HEAD
			while (getthetime(MCROSEC) - start < usec)
				;
=======
			while (get_time_of_day(MICROSEC) - start < usec)
			      ;
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
		}
	}
}
