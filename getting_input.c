/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:34:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/18 14:46:52 by stigkas          ###   ########.fr       */
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

static long	ft_atol(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		ft_error("Only positive numbers are acceptable!");
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) && (i < 11))
	{
		nbr = 10 * nbr + str[i] - '0';
		i++;
	}
	if ((i >= 11) || (nbr > MAX_INT))
		ft_error("The number should be smaller than the INT_MAX");
	return (nbr);
}

void	get_input(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		ft_error("Use values bigger than 6e4");
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}
