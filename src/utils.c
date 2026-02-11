/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:38 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 15:10:04 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	check_overflow(long result, char c)
{
	if (result > (LONG_MAX / 10))
		return (1);
	if (result == (LONG_MAX / 10) && (c - '0') > (LONG_MAX % 10))
		return (1);
	return (0);
}

long	ft_atol(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = parse_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(result, str[i]))
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int d)
{
	return (d >= '0' && d <= '9');
}

void	free_split_from(char **split, int i)
{
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
