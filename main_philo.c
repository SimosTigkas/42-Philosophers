/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:12:51 by marvin            #+#    #+#             */
/*   Updated: 2024/03/28 13:15:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (get_input(&table, av) == -1)
			printf("Wrong input!\n");
		else
		{
			init_data(&table);
			lets_eat_spaghetti(&table);
			clean_the_table(&table);
		}
	}
	else
		printf("Wrong_input! Try: ./philo 5 800 200 200 [5]\n");
	return (0);
}
