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

void *simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_the_threads_to_be_ready(philo->table);

    while (!simulation_is_finished(philo->table))
    {
        if (!get_bool(philo->table.table_mtx, philo->full))
            break ;
        is_eating(philo); //will be done tomorrow
        display_status(SLEEPING, philo);
        ft_usleep(philo->table->time_to_sleep, philo->table);
        is_thinking(philo); //will be done tomorrow
    }
}

void    lets_eat_spaghetti(t_table *table)
{
    int i;

    i = 0;
    if (table->nbr_limit_meals == 0)
        return ;
    else if (table->philo_nbr == 1)
        //please do something
    else
    {
        while (i < table->philo_nbr)
        {
            thread_hander(&table->philos[i].thread_id, simulation,
                 table->philos[i], CREATE);
            i++;
        }
    }
    table->start_simulation = get_time_of_day(MILLISEC);
    set_bool(&table->table_mtx, &table->threads_ready, true);
    i = 0;
    while (i < table->philo_nbr)
    {
        thread_hander(&table->philos[i].thread_id, NULL, NULL, JOIN);
        i++;
    }
}
