/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:09:59 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:37:01 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_doublelist **a, t_doublelist **b)
{
	int	size;

	size = get_list_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_four_five(a, b);
	else
		greedy_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_doublelist	*a;
	t_doublelist	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	normalize_arguments(argc, argv, &a);
	if (!a)
	{
		printf("Error\n");
		return (1);
	}
	push_swap(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
