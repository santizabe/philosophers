/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:20:49 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 12:00:47 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	create_threads(t_table *table)
{
	int			i;
	pthread_t	*t;

	i = 0;
	t = 0;
	while (i < table->n_philos)
	{
		t = &table->philos[i]->thread;
		pthread_create(t, NULL, &ph_routine, (void *)table->philos[i]);
		i++;
	}
	pthread_create(&(table->monitor), NULL, &ph_monitor, (void *)table);
}

void	join_threads(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->philos[i]->meal_time_handle);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->global);
	pthread_mutex_destroy(&table->fin);
}

void	free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		free(table->philos[i]);
		i++;
	}
	free(table->forks);
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table = (t_table *)malloc(sizeof(t_table));

	memset(table, 0, sizeof(t_table));
	if ((ac < 5 || ac > 6) || check_args(av))
	{
		ft_putstr_fd("Usage: ./philo number_of_philosophers ", 2);
		ft_putstr_fd("time_to_die time_to_eat time_to_sleep ", 2);
		ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
		return (-1);
	}
	data_init(table, av);
	create_threads(table);
	join_threads(table);
	destroy_mutex(table);
	free_all(table);
	return (0);
}

/*
	- init table
	- init philos
	- set forks
	- init mutexes
	- make philo routine
		- eat
	- make monitor routine
*/