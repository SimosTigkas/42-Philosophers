/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/18 18:13:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static void	init_the_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = 0;
		philo->meals_counter = 0;
		philo->table = table;
		i++;
	}
}

void	init_data(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = -1;
	table->philos = malloc((table->philo_nbr) * sizeof(t_philo *));
	if (table->philos == NULL)
		ft_error("Malloc error");
	table->forks = malloc((table->philo_nbr) * sizeof(t_fork *));
	if (table->forks == NULL)
		ft_error("Malloc error");
	while (i < table->philo_nbr)
	{
		mutex_hander(table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
	init_the_philo(&table);
}
