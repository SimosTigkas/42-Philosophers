/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:09:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/26 11:09:00 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	display_status(t_state status, t_philo *philo)
{
	long	time_has_passed;

	time_has_passed = getthetime(MLSEC) - philo->table->start_simulation;
	if (philo->full)
		return ;
	mtx_handler(&philo->table->display_mtx, LOCK);
	if (status == TAKE_FRST_FORK && !simulation_is_finished(philo->table))
		printf("%ld %d has taken the 1st fork %d.\n", time_has_passed,
			philo->id, philo->first_fork->fork_id);
	else if (status == TAKE_SCND_FORK && !simulation_is_finished(philo->table))
		printf("%ld %d has taken the 2nd fork %d.\n", time_has_passed,
			philo->id, philo->second_fork->fork_id);
	else if (status == EATING && !simulation_is_finished(philo->table))
		printf("%ld %d is eating the %ld meal.\n", time_has_passed,
			philo->id, philo->meals_counter);
	else if (status == SLEEPING && !simulation_is_finished(philo->table))
		printf("%ld %d is sleeping\n", time_has_passed, philo->id);
	else if (status == THINKING && !simulation_is_finished(philo->table))
		printf("%ld %d is thinking\n", time_has_passed, philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", time_has_passed, philo->id);
	mtx_handler(&philo->table->display_mtx, UNLOCK);
}
