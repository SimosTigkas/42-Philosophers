/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:16 by stigkas           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/26 11:08:16 by stigkas          ###   ########.fr       */
=======
/*   Updated: 2024/03/25 20:07:16 by marvin           ###   ########.fr       */
>>>>>>> 161cb8bc798b1afbfe7a366178f859e7be1a2af7
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		get_input(&table, av);
		init_data(&table);
		lets_eat_spaghetti(&table);
		clean_the_table(&table);
	}
	else
		ft_error("Wrong_input! Try: ./philo 5 800 200 200 [5]");
	return (0);
}
