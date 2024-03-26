/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:50:07 by stigkas           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/26 11:07:36 by stigkas          ###   ########.fr       */
=======
/*   Updated: 2024/03/25 20:14:07 by marvin           ###   ########.fr       */
>>>>>>> 161cb8bc798b1afbfe7a366178f859e7be1a2af7
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

<<<<<<< HEAD
void	clean_the_table(t_table *table)
=======
void clean_the_table(t_table *table)
>>>>>>> 161cb8bc798b1afbfe7a366178f859e7be1a2af7
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		mutex_handler(&philo->philo_mtx, DESTROY);
		i++;
	}
	mutex_handler(&table->display_mtx, DESTROY);
	mutex_handler(&table->table_mtx, DESTROY);
	free(table->forks);
	free(table->philos);
}

void	ft_error(char *msg)
{
	printf("%s\n", msg);
}

long	getthetime(t_time time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		ft_error("Gettimeofday did not work as expected");
	if (time == SEC)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time == MLSEC)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time == MCROSEC)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		ft_error("Wrong input!! Try SEC, MILLISEC or MICROSEC.");
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
		if (time_remained > 1e3)
			usleep(time_remained / 2);
		else
		{
			while (getthetime(MCROSEC) - start < usec)
				;
		}
	}
}
