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

void is_thinking(t_philo *philo, bool not_started)
{
	long	thinking_time;
	long	sleeping_time;
	long	eating_time;

	if (!not_started)
		display_status(THINKING, philo);
	if (philo->table->philo_nbr % 2 == 0)
		return ;
	sleeping_time = philo->table->time_to_sleep;
	eating_time = philo->table->time_to_eat;
	thinking_time = (2 * eating_time) - sleeping_time;
	if (thinking_time < 0)
		thinking_time = 0;
	ft_usleep(thinking_time * 0.42, philo->table);
}

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_the_threads_to_be_ready(philo->table);
	set_long(&philo->philo_mtx, &philo->time_from_last_meal, getthetime(MLSEC));
	mutex_handler(&philo->table->table_mtx, LOCK);
	philo->table->nbr_of_threads_running++;
	mutex_handler(&philo->table->table_mtx, UNLOCK);
	display_status(TAKE_FRST_FORK, philo);
	while (!simulation_is_finished(philo->table))
		ft_usleep(200, philo->table);
	return (NULL);
}

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

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_the_threads_to_be_ready(philo->table);
	set_long(&philo->philo_mtx, &philo->time_from_last_meal, getthetime(MLSEC));
	mutex_handler(&philo->table->table_mtx, LOCK);
	philo->table->nbr_of_threads_running++;
	mutex_handler(&philo->table->table_mtx, UNLOCK);
	check_sleep(philo);
	while (!simulation_is_finished(philo->table))
	{
		if (get_bool(&philo->philo_mtx, &philo->full))
			break ;
		is_eating(philo);
		display_status(SLEEPING, philo);
		ft_usleep(philo->table->time_to_sleep, philo->table);
		is_thinking(philo, false);
	}
	return (NULL);
}

void	lets_eat_spaghetti(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		thread_handler(&table->philos[0].thread_id, one_philo, &table->philos[0], CREATE);
	else
	{
		while (i < table->philo_nbr)
		{
			thread_handler(&table->philos[i].thread_id, simulation,
				&table->philos[i], CREATE);
			i++;
		}
	}
	thread_handler(&table->death_checker, ft_death_checker, table, CREATE);
	table->start_simulation = getthetime(MLSEC);
	set_bool(&table->table_mtx, &table->threads_ready, true);
	i = 0;
	while (i < table->philo_nbr)
	{
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_bool(&table->table_mtx, &table->end_simulation, true);
	thread_handler(&table->death_checker, NULL, NULL, JOIN);
}
