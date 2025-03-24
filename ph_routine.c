/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:52:53 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 17:35:57 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_check_routine(t_table *table)
{
	pthread_mutex_lock(&table->fin);
	if (table->finish)
	{
		pthread_mutex_unlock(&table->fin);
		return (0);
	}
	pthread_mutex_unlock(&table->fin);
	return (1);
}

void	ft_set_forks(t_philo *philo)
{
	t_mtx	*fork1;
	t_mtx	*fork2;

	fork1 = &philo->table->forks[philo->forks[0]];
	fork2 = &philo->table->forks[philo->forks[1]];
	pthread_mutex_lock(fork1);
	pthread_mutex_lock(fork2);
	ft_print_lock("has taken l fork", philo);
	ft_print_lock("has taken r fork", philo);
	pthread_mutex_lock(&philo->meal_time_handle);
	philo->last_meal = ft_get_time_now();
	philo->n_meal += 1;
	pthread_mutex_unlock(&philo->meal_time_handle);
	ft_print_lock("is eating", philo);
	usleep(philo->table->tteat * 1000);
	pthread_mutex_unlock(fork1);
	pthread_mutex_unlock(fork2);
}

void	*ph_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(100);
	while (ft_check_routine(philo->table) != 0)
	{
		if (ft_check_routine(philo->table) != 0)
			ft_set_forks(philo);
		if (ft_check_routine(philo->table) != 0)
		{
			ft_print_lock("is sleeping", philo);
			usleep(philo->table->ttsleep * 1000);
		}
		if (ft_check_routine(philo->table) != 0)
			ft_print_lock("is thinking", philo);
	}
	return (NULL);
}
