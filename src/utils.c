/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:12:03 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 11:33:40 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_print_lock(char *s, t_philo *philo)
{
	time_t	curr;

	curr = ft_get_time_now() - philo->table->start;
	pthread_mutex_lock(&philo->table->global);
	printf("%lu philo %i %s\n", curr, philo->id, s);
	pthread_mutex_unlock(&philo->table->global);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

t_ulong	ft_atol(const char *str)
{
	t_ulong	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res);
}
