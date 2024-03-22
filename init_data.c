/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/22 18:42:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static void	get_the_forks(t_philo *philo, t_fork *forks, int i)
{
	long	all_philos;

	all_philos = philo->table->philo_nbr;
	if ((philo->id % 2) == 0)
	{
		philo->first_fork = &forks[(i + 1) % all_philos];
		philo->second_fork = &forks[i];
	}
	else
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % all_philos];
	}
}

static void	init_the_philo(t_table *table)
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
		mutex_handler(&philo->philo_mtx, INIT);
		philo->table = table;
		get_the_forks(philo, table->forks, i);
		i++;
	}
}

void	init_data(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->threads_ready = false;
	table->philos = (t_philo *)malloc(table->philo_nbr * sizeof(t_philo));
	if (table->philos == NULL)
		ft_error("Malloc error");
	mutex_handler(&table->table_mtx, INIT);
	mutex_handler(&table->display_mtx, INIT);
	mutex_handler(&table->philos->philo_mtx, INIT);
	table->forks = (t_fork *)malloc(table->philo_nbr * sizeof(t_fork));
	if (table->forks == NULL)
		ft_error("Malloc error");
	while (i < table->philo_nbr)
	{
		mutex_handler(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
	init_the_philo(table);
}
