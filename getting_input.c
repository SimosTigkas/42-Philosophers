/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:34:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/28 13:38:56 by marvin           ###   ########.fr       */
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
		printf("Only positive numbers are acceptable!");
		return (-2);
	}
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) && (i < 11))
	{
		nbr = 10 * nbr + str[i] - '0';
		i++;
	}
	if (!ft_isdigit(str[i]))
			return (-2);
	if ((i >= 11) || (nbr > MAX_INT))
	{
		printf("The number should be smaller than the INT_MAX");
		return (-2);
	}
	return (nbr);
}

int	get_input(t_table *table, char **av)
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
	if (table->time_to_die == -2 * 1e3
		|| table->time_to_eat == -2 * 1e3
		|| table->time_to_sleep == -2 * 1e3)
		return (-1);
	else if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
	{
		printf("Use values bigger than 6e4");
		return (-1);
	}
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
	return (0);
}
