/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:25 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:38:05 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_doublelist **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_doublelist **a)
{
	int	first;
	int	second;
	int	third;

	if (!*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

void	sort_four_five(t_doublelist **a, t_doublelist **b)
{
	int	min_pos;
	int	size;

	size = get_list_size(*a);
	while (size > 3)
	{
		min_pos = get_min_position(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a, 1);
		}
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a, 1);
		}
		pb(a, b);
		size = get_list_size(*a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
