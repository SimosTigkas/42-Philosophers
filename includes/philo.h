/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:25:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/03/22 18:57:15 by stigkas          ###   ########.fr       */
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
# include <stdbool.h>
# include <errno.h>
# define MAX_INT 2147483647

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				philo_nbr;
	long				start_simulation;
	bool				end_simulation;
	bool				threads_ready;
	t_fork				*forks;
	t_philo				*philos;
	pthread_mutex_t		table_mtx;
	pthread_mutex_t		display_mtx;
}	t_table;

struct s_philo
{
	int				id;
	bool			full;
	long			meals_counter;
	long			time_from_last_meal;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	t_table			*table;
	pthread_mutex_t	philo_mtx;
};

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FRST_FORK,
	TAKE_SCND_FORK,
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

typedef enum e_time
{
	SEC,
	MLSEC,
	MCROSEC
}	t_time;

void	ft_error(char *msg);
void	get_input(t_table *table, char **av);
void	init_data(t_table *table);
void	mutex_handler(pthread_mutex_t *mtx, t_mtx_action act);
void	thread_handler(pthread_t *thread, void *(*f)(void *), void *data,
			t_thread_action act);
void	lets_eat_spaghetti(t_table *table);
long	get_long(pthread_mutex_t *mtx, long value);
void	set_long(pthread_mutex_t *mtx, long *target, long value);
bool	get_bool(pthread_mutex_t *mtx, bool status);
void	set_bool(pthread_mutex_t *mtx, bool *target, bool status);
void	wait_the_threads_to_be_ready(t_table *table);
long	getthetime(t_time time);
bool	simulation_is_finished(t_table *table);
void	ft_usleep(long usec, t_table *table);
void	display_status(t_state status, t_philo *philo);
// void	thread_check(int result, t_thread_action act);
// void	mutex_check(int result, t_mtx_action act);

#endif