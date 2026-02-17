/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:31:55 by szapata-          #+#    #+#             */
/*   Updated: 2025/03/24 11:33:15 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *str)
{
	t_uint	res;

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

int	check_number(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (-1);
		arg++;
	}
	return (0);
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_number(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}
