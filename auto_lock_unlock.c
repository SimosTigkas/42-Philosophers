/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_lock_unlock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:22:20 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 19:22:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

<<<<<<< HEAD
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

long	get_long(pthread_mutex_t *mtx, long value)
{
	long	returning_value;

	mutex_handler(mtx, LOCK);
	returning_value = value;
	mutex_handler(mtx, UNLOCK);
	return (returning_value);
}

bool	simulation_is_finished(t_table *table)
{
	return (get_bool(&table->table_mtx, &table->end_simulation));
=======
void    set_bool(pthread_mutex_t *mtx, bool *target, bool status)
{
    mutex_hander(mtx, LOCK);
    *target = status;
    mutex_hander(mtx, UNLOCK);
}

bool get_bool(pthread_mutex_t *mtx, bool status)
{
    bool returning_status;

    mutex_hander(mtx, LOCK);
    returning_status = status;
    mutex_hander(mtx, UNLOCK);
    return (returning_status);
}

void    set_long(pthread_mutex_t *mtx, long *target, long value)
{
    mutex_hander(mtx, LOCK);
    *target = value;
    mutex_hander(mtx, UNLOCK);
}

long get_long(pthread_mutex_t *mtx, long value)
{
    long returning_value;

    mutex_hander(mtx, LOCK);
    returning_value = value;
    mutex_hander(mtx, UNLOCK);
    return (returning_value);
}

bool simulation_is_finished(t_table *table)
{
    return (get_bool(&table->table_mtx, &table->end_simulation));
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
}
