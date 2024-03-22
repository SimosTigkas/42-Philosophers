/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:16 by stigkas           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/22 14:17:56 by stigkas          ###   ########.fr       */
=======
/*   Updated: 2024/03/21 13:20:41 by marvin           ###   ########.fr       */
>>>>>>> d3f43b2813e6258cf0918167af9fc9a35b5e81e0
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		get_input(&table, av);
		init_data(&table);
		lets_eat_spaghetti(&table);
	}
	else
	{
		ft_error("Wrong_input");
		ft_error("Try something like-> ./philo 5 800 200 200 [5]");
	}
	return (0);
}
