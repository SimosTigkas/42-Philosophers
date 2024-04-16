/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:12:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/16 09:42:09 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (get_input(&table, av, ac) == -1)
			printf("Wrong input!\n");
		else
		{
			if (!init_data(&table) || !lets_eat_spaghetti(&table, -1))
				printf("It did not work, try again!!\n");
			if (!clean_the_table(&table))
				printf("Cleaning went wrong..\n");
		}
	}
	else
		printf("Wrong_input! Try: ./philo 5 800 200 200 [5]\n");
	return (0);
}
