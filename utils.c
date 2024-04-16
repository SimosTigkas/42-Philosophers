/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:19 by stigkas           #+#    #+#             */
/*   Updated: 2024/04/16 09:42:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	clean_the_table(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		if (!mtx_handler(&philo->philo_mtx, DESTROY))
			return (0);
		i++;
	}
	if (!mtx_handler(&table->display_mtx, DESTROY)
		|| !mtx_handler(&table->table_mtx, DESTROY))
		return (0);
	free(table->forks);
	free(table->philos);
	return (1);
}

long	getthetime(t_time time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		printf("Gettimeofday did not work as expected");
	if (time == SEC)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time == MLSEC)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time == MCROSEC)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		printf("Wrong input!! Try SEC, MILLISEC or MICROSEC.");
	return (42);
}

void	ft_usleep(long usec, t_table *table)
{
	long	start;
	long	time_passed;
	long	time_remained;

	start = getthetime(MCROSEC);
	while (getthetime(MCROSEC) - start < usec)
	{
		if (simulation_is_finished(table))
			break ;
		time_passed = getthetime(MCROSEC) - start;
		time_remained = usec - time_passed;
		if (time_remained > 1e4)
			usleep(time_remained / 2);
		else
		{
			while (getthetime(MCROSEC) - start < usec)
				;
		}
	}
}
