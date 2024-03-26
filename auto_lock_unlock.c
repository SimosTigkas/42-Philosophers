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

void	set_bool(pthread_mutex_t *mtx, bool *target, bool status)
{
	mutex_handler(mtx, LOCK);
	*target = status;
	mutex_handler(mtx, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mtx, bool status)
{
	bool	returning_status;

	mutex_handler(mtx, LOCK);
	returning_status = status;
	mutex_handler(mtx, UNLOCK);
	return (returning_status);
}

void	set_long(pthread_mutex_t *mtx, long *target, long value)
{
	mutex_handler(mtx, LOCK);
	*target = value;
	mutex_handler(mtx, UNLOCK);
}

long	get_long(pthread_mutex_t *mtx, long *value)
{
	long	returning_value;

	mutex_handler(mtx, LOCK);
	returning_value = *value;
	mutex_handler(mtx, UNLOCK);
	return (returning_value);
}

bool	simulation_is_finished(t_table *table)
{
	return (get_bool(&table->table_mtx, table->end_simulation));
}
