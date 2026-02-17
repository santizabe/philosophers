/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:57:06 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 11:32:46 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

typedef pthread_mutex_t	t_mtx;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct s_table
{
	pthread_t		monitor;
	int				n_philos;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	t_uint			meals;
	time_t			start;
	struct s_philo	**philos;
	t_mtx			*forks;
	t_mtx			global;
	t_mtx			fin;
	int				finish;
	int				start_philos;
}	t_table;

typedef struct s_philo
{
	pthread_t	thread;
	t_table		*table;
	int			id;
	int			forks[2];
	t_uint		n_meal;
	time_t		last_meal;
	t_mtx		meal_time_handle;
}	t_philo;

void	*ph_routine(void *arg);
void	ft_philo_init(t_table *table);
void	data_init(t_table *table, char **argv);
time_t	ft_get_time_now(void);
void	*ph_monitor(void *arg);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_print_lock(char *s, t_philo *philo);
int		ft_isdigit(int c);
int		check_args(char **argv);

#endif