/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:50:20 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 19:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

<<<<<<< HEAD
void	wait_the_threads_to_be_ready(t_table *table)
{
	while (!get_bool(&table->table_mtx, &table->threads_ready))
		;
}
=======
void    wait_the_threads_to_be_ready(t_table *table)
{
    while (!get_bool(&table->table_mtx, &table->threads_ready))
        ;
}
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
