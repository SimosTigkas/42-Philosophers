/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:42:48 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/22 18:38:41 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	mutex_check(int result, t_mtx_action act)
{
	if (result == 0)
		return ;
	if (result == EINVAL && (LOCK == act || UNLOCK == act))
	{
		ft_error("The values specified by act is not valid"
			" or The value specified by mutex is invalid\n");
	}
	else if (result == ENOMEM)
		ft_error("Not enough memory to allocate to create another mutex\n");
	else if (result == EINVAL && act == INIT)
		ft_error("The valuse specified by attr is not valid\n");
	else if (result == EBUSY)
		ft_error("Mutex is locked\n");
	else if (result == EDEADLK)
		ft_error("Deadlock would occur if "
			"the thread blocked waiting for mutex\n");
	else if (result == EPERM)
		ft_error("The current thread does not hold a lock on mutex\n");
}

void	mutex_handler(pthread_mutex_t *mtx, t_mtx_action act)
{
	if (act == INIT)
		mutex_check(pthread_mutex_init(mtx, NULL), INIT);
	else if (act == DESTROY)
		mutex_check(pthread_mutex_destroy(mtx), DESTROY);
	else if (act == LOCK)
		mutex_check(pthread_mutex_lock(mtx), LOCK);
	else if (act == UNLOCK)
		mutex_check(pthread_mutex_unlock(mtx), UNLOCK);
	else
		ft_error("Wrong mutex action");
}

void	thread_check(int result, t_thread_action act)
{
	if (!result)
		return ;
	if (EAGAIN == result)
		ft_error("No resources to create another thread");
	else if (EPERM == result)
		ft_error("The caller does not have appropriate permission\n");
	else if (EINVAL == result && act == CREATE)
		ft_error("The value specified by attr is invalid.");
	else if (EINVAL == result && (act == JOIN || act == DETACH))
		ft_error("The value specified by thread is not joinable\n");
	else if (ESRCH == result)
		ft_error("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == result)
		ft_error("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}

void	thread_handler(pthread_t *thread, void *(*routine)(void *),
		void *data, t_thread_action act)
{
	if (act == CREATE)
		thread_check(pthread_create(thread, NULL, routine, data), CREATE);
	else if (act == JOIN)
		thread_check(pthread_join(*thread, NULL), JOIN);
	else if (act == DETACH)
		thread_check(pthread_detach(*thread), DETACH);
	else
		ft_error("Wrong thread action"
			"Use CREATE, JOIN or DETACH\n");
}
