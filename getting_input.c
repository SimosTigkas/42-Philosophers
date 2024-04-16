/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:34:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/04/16 09:42:02 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static long	ft_atol(char *str, int i, long nbr)
{
	if (ft_isspace(str[i]))
		return (-2);
	if (str[i] == '-')
	{
		printf("Only positive numbers are acceptable!\n");
		return (-2);
	}
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) && (i < 11))
	{
		nbr = 10 * nbr + str[i] - '0';
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		return (-2);
	if ((i >= 11) || (nbr > MAX_INT))
	{
		printf("The number should be smaller than the INT_MAX\n");
		return (-2);
	}
	return (nbr);
}

int	get_input(t_table *table, char **av, int ac)
{
	table->philo_nbr = ft_atol(av[1], 0, 0);
	table->time_to_die = ft_atol(av[2], 0, 0) * 1e3;
	table->time_to_eat = ft_atol(av[3], 0, 0) * 1e3;
	table->time_to_sleep = ft_atol(av[4], 0, 0) * 1e3;
	if (!table->philo_nbr)
	{
		printf("No philos, no dinner\n");
		return (-1);
	}
	if (table->philo_nbr == -2)
		return (-1);
	else if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
	{
		printf("Use values bigger than 6e4\n");
		return (-1);
	}
	if (ac == 6 && ft_atol(av[5], 0, 0) > 0)
		table->nbr_limit_meals = ft_atol(av[5], 0, 0);
	else if (ac == 6)
		return (-1);
	return (0);
}
