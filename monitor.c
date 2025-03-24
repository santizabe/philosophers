/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:02:46 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 11:29:46 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ph_are_alive(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_time_handle);
		if (ft_get_time_now() - table->philos[i]->last_meal >= table->ttdie)
		{
			ft_print_lock("died", table->philos[i]);
			pthread_mutex_unlock(&table->philos[i]->meal_time_handle);
			return (0);
		}
		pthread_mutex_unlock(&table->philos[i]->meal_time_handle);
		i++;
	}
	return (1);
}

int	ph_meals_finished(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_time_handle);
		if (table->philos[i]->n_meal < table->meals)
		{
			pthread_mutex_unlock(&table->philos[i]->meal_time_handle);
			return (0);
		}
		pthread_mutex_unlock(&table->philos[i]->meal_time_handle);
		i++;
	}
	return (1);
}

void	*ph_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (!ph_are_alive(table) || ph_meals_finished(table))
		{
			pthread_mutex_lock(&table->fin);
			table->finish = 1;
			pthread_mutex_unlock(&table->fin);
			break ;
		}
	}
	return (NULL);
}
