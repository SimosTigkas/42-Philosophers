/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:52 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/26 11:08:52 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static bool	philo_is_dead(t_philo *philo)
{
	long	time_passed;

	if (get_bool(&philo->philo_mtx, philo->full))
		return (false);
	time_passed = getthetime(MLSEC) - \
		get_long(&philo->philo_mtx, &philo->time_from_last_meal);
	if (time_passed > (philo->table->time_to_die / 1e3))
		return (true);
	return (false);
}

void	*is_dead(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!threads_running(&table->table_mtx, \
			&table->nbr_of_threads_running, table->philo_nbr))
		;
	while (!simulation_is_finished(table))
	{
		i = 0;
		while ((i < table->philo_nbr) && !simulation_is_finished(table))
		{
			if (philo_is_dead(table->philos + i))
			{
				set_bool(&table->table_mtx, &table->end_simulation, true);
				display_status(DEAD, table->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}
