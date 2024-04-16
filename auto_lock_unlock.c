/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_lock_unlock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:22 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/26 11:08:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*set_bool(pthread_mutex_t *mtx, bool *target, bool status)
{
	if (!mtx_handler(mtx, LOCK))
		return (NULL);
	*target = status;
	mtx_handler(mtx, UNLOCK);
	return (NULL);
}

bool	get_bool(pthread_mutex_t *mtx, bool status)
{
	bool	returning_status;

	if (!mtx_handler(mtx, LOCK))
		return (false);
	returning_status = status;
	if (!mtx_handler(mtx, UNLOCK))
		return (false);
	return (returning_status);
}

void	*set_long(pthread_mutex_t *mtx, long *target, long value)
{
	if (!mtx_handler(mtx, LOCK))
		return (NULL);
	*target = value;
	mtx_handler(mtx, UNLOCK);
	return (NULL);
}

long	get_long(pthread_mutex_t *mtx, long *value)
{
	long	returning_value;

	if (!mtx_handler(mtx, LOCK))
		return (0);
	returning_value = *value;
	if (!mtx_handler(mtx, UNLOCK))
		return (0);
	return (returning_value);
}

bool	simulation_is_finished(t_table *table)
{
	return (get_bool(&table->table_mtx, table->end_simulation));
}
