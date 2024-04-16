/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:13:46 by marvin            #+#    #+#             */
/*   Updated: 2024/04/16 09:39:21 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"


static void	get_the_forks(t_philo *philo, t_fork *forks, int i)
{
	long	all_philos;

	all_philos = philo->table->philo_nbr;
	if ((philo->id % 2) == 1)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % all_philos];
	}
	else
	{
		philo->first_fork = &forks[(i + 1) % all_philos];
		philo->second_fork = &forks[i];
	}
}

static int	init_the_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		if (!mtx_handler(&philo->philo_mtx, INIT))
			return (0);
		philo->table = table;
		get_the_forks(philo, table->forks, i);
		i++;
	}
	return (1);
}

int	init_data(t_table *table)
{
	int	i;

	i = -1;
	table->nbr_of_threads_running = 0;
	table->end_simulation = false;
	table->threads_ready = false;
	table->philos = (t_philo *)malloc(table->philo_nbr * sizeof(t_philo));
	if (table->philos == NULL)
		return (0);
	if (!mtx_handler(&table->table_mtx, INIT)
		|| !mtx_handler(&table->display_mtx, INIT)
		|| !mtx_handler(&table->philos->philo_mtx, INIT))
		return (0);
	table->forks = (t_fork *)malloc(table->philo_nbr * sizeof(t_fork));
	if (table->forks == NULL)
		return (0);
	while (++i < table->philo_nbr)
	{
		if (!mtx_handler(&table->forks[i].fork, INIT))
			return (0);
		table->forks[i].fork_id = i;
	}
	if (!init_the_philo(table))
		return (0);
	return (1);
}
