/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:37:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/20 12:37:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void display_status(t_state status, t_philo *philo)
{
    long    time_has_passed;

    time_has_passed = get_time_of_day(MILLISEC) - philo->table->start_simulation;
    if (philo->full)
        return ;
    mutex_hander(&philo->table->display_mtx, LOCK);
    if (status == TAKE_FIRST_FORK && !simulation_is_finished(philo->table))
        printf("%6ld %d has taken the 1st fork %d.\n", time_has_passed, 
                philo->id, philo->first_fork->fork_id);
    else if (status == TAKE_SECOND_FORK && !simulation_is_finished(philo->table))
        printf("%6ld %d has taken the 2nd fork %d.\n", time_has_passed,
                philo->id, philo->second_fork->fork_id);
    else if (status == EATING && !simulation_is_finished(philo->table))
        printf("%6ld %d is eating the %ld meal.\n", time_has_passed,
                philo->id, philo->meals_counter);
    else if (status == SLEEPING && !simulation_is_finished(philo->table))
        printf("%6ld %d is sleeping\n", time_has_passed, philo->id);
    else if (status == THINKING && !simulation_is_finished(philo->table))
        printf("%6ld %d is thinking\n", time_has_passed, philo->id);
    else if (status == DEAD)
        printf("%6ld %d died\n", time_has_passed, philo->id);
    mutex_hander(&philo->table->display_mtx, UNLOCK);
}
