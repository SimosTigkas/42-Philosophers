/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_eat_spaghetti.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:25:31 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 18:25:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static void	is_eating(t_philo *philo)
{
	mutex_handler(&philo->first_fork->fork, LOCK);
	display_status(TAKE_FRST_FORK, philo);
	mutex_handler(&philo->second_fork->fork, LOCK);
	display_status(TAKE_SCND_FORK, philo);
	set_long(&philo->philo_mtx, &philo->time_from_last_meal, getthetime(MLSEC));
	philo->meals_counter++;
	display_status(EATING, philo);
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	mutex_handler(&philo->first_fork->fork, UNLOCK);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
}

static void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_the_threads_to_be_ready(philo->table);
	while (!simulation_is_finished(philo->table))
	{
		if (get_bool(&philo->table->table_mtx, philo->full))
			break ;
		is_eating(philo);
		display_status(SLEEPING, philo);
		ft_usleep(philo->table->time_to_sleep, philo->table);
	}
	return (NULL);
}

void	lets_eat_spaghetti(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	// else if (table->philo_nbr == 1)
 	// //   will be probably done in the weekend
	else
	{
		while (i < table->philo_nbr)
		{
			thread_handler(&table->philos[i].thread_id, simulation,
				&table->philos[i], CREATE);
			i++;
		}
	}
	table->start_simulation = getthetime(MLSEC);
	set_bool(&table->table_mtx, &table->threads_ready, true);
	i = 0;
	while (i < table->philo_nbr)
	{
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
}
