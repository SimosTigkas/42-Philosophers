/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_eat_spaghetti.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:09:27 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/26 11:09:27 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"


void	is_thinking(t_philo *philo, bool not_started)
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

void	*one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_the_threads_to_be_ready(philo->table);
	set_long(&philo->philo_mtx, &philo->time_from_last_meal, getthetime(MLSEC));
	if (!mtx_handler(&philo->table->table_mtx, LOCK))
		return (NULL);
	philo->table->nbr_of_threads_running++;
	if (!mtx_handler(&philo->table->table_mtx, UNLOCK))
		return (NULL);
	display_status(TAKE_FRST_FORK, philo);
	while (!simulation_is_finished(philo->table))
		ft_usleep(200, philo->table);
	return (NULL);
}

static int	is_eating(t_philo *philo)
{
	if (!mtx_handler(&philo->first_fork->fork, LOCK))
		return (0);
	display_status(TAKE_FRST_FORK, philo);
	if (!mtx_handler(&philo->second_fork->fork, LOCK))
		return (0);
	display_status(TAKE_SCND_FORK, philo);
	set_long(&philo->philo_mtx, &philo->time_from_last_meal, getthetime(MLSEC));
	philo->meals_counter++;
	display_status(EATING, philo);
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	if (!mtx_handler(&philo->first_fork->fork, UNLOCK)
		|| !mtx_handler(&philo->second_fork->fork, UNLOCK))
		return (0);
	return (1);
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_the_threads_to_be_ready(philo->table);
	set_long(&philo->philo_mtx, &philo->time_from_last_meal, getthetime(MLSEC));
	if (!mtx_handler(&philo->table->table_mtx, LOCK))
		return (NULL);
	philo->table->nbr_of_threads_running++;
	if (!mtx_handler(&philo->table->table_mtx, UNLOCK))
		return (NULL);
	check_sleep(philo);
	while (!simulation_is_finished(philo->table))
	{
		if (get_bool(&philo->philo_mtx, philo->full)
			|| !is_eating(philo))
			break ;
		display_status(SLEEPING, philo);
		ft_usleep(philo->table->time_to_sleep, philo->table);
		is_thinking(philo, false);
	}
	return (NULL);
}

int	lets_eat_spaghetti(t_table *table, int i)
{
	if (table->philo_nbr == 1)
	{
		if (!thread_handler(&table->philos[0].thread_id, \
				one, &table->philos[0], CREATE))
			return (0);
	}
	else
	{
		while (++i < table->philo_nbr)
			if (!thread_handler(&table->philos[i].thread_id, simulation,
					&table->philos[i], CREATE))
				return (0);
	}
	if (!thread_handler(&table->death_checker, is_dead, table, CREATE))
		return (0);
	table->start_simulation = getthetime(MLSEC);
	set_bool(&table->table_mtx, &table->threads_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		if (!thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN))
			return (0);
	set_bool(&table->table_mtx, &table->end_simulation, true);
	if (!thread_handler(&table->death_checker, NULL, NULL, JOIN))
		return (0);
	return (1);
}
