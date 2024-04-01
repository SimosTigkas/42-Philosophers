/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:04 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/26 11:08:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	wait_the_threads_to_be_ready(t_table *table)
{
	while (!get_bool(&table->table_mtx, &table->threads_ready))
		;
}

bool	threads_running(pthread_mutex_t *mtx, long *threads, long philo_nbr)
{
	bool	all_threads;

	all_threads = false;
	mutex_handler(mtx, LOCK);
	if (*threads == philo_nbr)
		all_threads = true;
	mutex_handler(mtx, UNLOCK);
	return (all_threads);
}

void	check_sleep(t_philo *philo)
{
	if (philo->table->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
			is_thinking(philo, true);
	}
}
