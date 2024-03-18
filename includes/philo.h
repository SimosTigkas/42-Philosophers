/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:25:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/18 18:00:34 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# define MAX_INT 2147483647

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_table
{
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				philo_nbr;
    t_philo                *philos;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				full;
	long			meals_counter;
}	t_philo;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_RIGHT_FORK,
	TAKE_LEFT_FORK,
	DEAD
}	t_state;

typedef enum e_mtx_action
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}	t_mtx_action;

typedef enum e_thread_action
{
	CREATE,
	DETACH,
	JOIN
}	t_thread_action;

void	ft_error(char *msg);
void	get_input(t_table *table, char **av);
void	init_data(t_table *table);
void	mutex_hander(pthread_mutex_t mtx, t_mtx_action act);

#endif
