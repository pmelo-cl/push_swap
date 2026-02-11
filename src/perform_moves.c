/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:41:06 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:52:46 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_double_rot(t_doublelist **a, t_doublelist **b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	perform_moves(t_doublelist **stack_a, t_doublelist **stack_b,
		int cost_a, int cost_b)
{
	apply_double_rot(stack_a, stack_b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(stack_a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_a, 1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_b, 1);
		cost_b++;
	}
}
