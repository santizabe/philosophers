/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:47:24 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 11:58:48 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_fork_init(t_table *table)
{
	int	i;

	table->forks = (t_mtx *)malloc(table->n_philos * sizeof(t_mtx));
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	ft_philo_init(t_table *table)
{
	int	i;
	int	res;

	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		table->philos[i]->table = table;
		table->philos[i]->last_meal = table->start;
		table->philos[i]->id = i + 1;
		table->philos[i]->forks[0] = i;
		table->philos[i]->forks[1] = i + 1;
		if (i + 1 == table->n_philos)
			table->philos[i]->forks[1] = 0;
		if ((res = pthread_mutex_init(&table->philos[i]->meal_time_handle, NULL)))
			printf("error: %d\n", res);
		i++;
	}
}

void	data_init(t_table *table, char **argv)
{
	argv++;
	table->n_philos = ft_atoi(*argv++);
	table->ttdie = ft_atoi(*argv++);
	table->tteat = ft_atoi(*argv++);
	table->ttsleep = ft_atoi(*argv++);
	table->meals = -1;
	table->finish = 0;
	table->start = ft_get_time_now();
	table->start_philos = 0;
	if (*argv)
		table->meals = ft_atoi(*argv);
	table->philos = (t_philo **)malloc(table->n_philos * sizeof(t_philo *));
	ft_philo_init(table);
	ft_fork_init(table);
	pthread_mutex_init(&table->global, NULL);
	pthread_mutex_init(&table->fin, NULL);
}
