/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:25:59 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 15:11:05 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_argument(char *arg, t_doublelist **head, int *error)
{
	long	num;
	int		local_error;
	int		i;
	char	**numbers;

	i = 0;
	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (*error = 1, (void)0);
	while (numbers[i] && !*error)
	{
		local_error = 0;
		if (!is_valid_number(numbers[i]))
			return (free_split_from(numbers, i), *error = 1, (void)0);
		num = ft_atol(numbers[i], &local_error);
		if (local_error || num < INT_MIN || num > INT_MAX)
			return (free_split_from(numbers, i), *error = 1, (void)0);
		add_back(head, create_node(get_last_index(*head) + 1, (int)num));
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	normalize_arguments(int argc, char **argv, t_doublelist **head)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (i < argc && !error)
	{
		process_argument(argv[i], head, &error);
		i++;
	}
	if (error || check_duplicates(*head))
	{
		free_list(head);
		*head = NULL;
	}
}
