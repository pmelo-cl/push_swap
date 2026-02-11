/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:10 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:41:38 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_position(t_doublelist **stack_a, int value_b)
{
	t_doublelist	*tmp_a;
	int				target_index;
	int				min_diff;

	tmp_a = *stack_a;
	target_index = -1;
	min_diff = __INT_MAX__;
	while (tmp_a)
	{
		if (tmp_a->value > value_b && (tmp_a->value - value_b) < min_diff)
		{
			min_diff = tmp_a->value - value_b;
			target_index = tmp_a->index;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index == -1)
		target_index = get_min_position(*stack_a);
	return (target_index);
}

void	calculate_costs(t_doublelist **stack_a, t_doublelist **stack_b)
{
	t_doublelist	*tmp_b;
	int				size_a;
	int				size_b;
	int				pos_a;
	int				pos_b;

	size_a = get_list_size(*stack_a);
	size_b = get_list_size(*stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		pos_b = tmp_b->index;
		if (pos_b <= size_b / 2)
			tmp_b->cost_b = pos_b;
		else
			tmp_b->cost_b = (pos_b - size_b);
		pos_a = find_target_position(stack_a, tmp_b->value);
		if (pos_a <= size_a / 2)
			tmp_b->cost_a = pos_a;
		else
			tmp_b->cost_a = (pos_a - size_a);
		tmp_b = tmp_b->next;
	}
}

void	execute_cheapest_move(t_doublelist **stack_a, t_doublelist **stack_b)
{
	t_doublelist	*tmp_b;
	t_doublelist	*cheapest;
	int				min_cost;
	int				total_cost;

	tmp_b = *stack_b;
	cheapest = tmp_b;
	min_cost = abs(tmp_b->cost_a) + abs(tmp_b->cost_b);
	while (tmp_b)
	{
		total_cost = abs(tmp_b->cost_a) + abs(tmp_b->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	perform_moves(stack_a, stack_b, cheapest->cost_a, cheapest->cost_b);
	pa(stack_a, stack_b);
}

void	final_rotate(t_doublelist **stack_a)
{
	int	min_pos;
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	min_pos = get_min_position(*stack_a);
	size = get_list_size(*stack_a);
	if (min_pos == 0)
		return ;
	if (min_pos <= size / 2)
	{
		while (min_pos != 0)
		{
			ra(stack_a, 1);
			min_pos = get_min_position(*stack_a);
		}
	}
	else
	{
		while (min_pos != 0)
		{
			rra(stack_a, 1);
			min_pos = get_min_position(*stack_a);
		}
	}
}

void	greedy_sort(t_doublelist **stack_a, t_doublelist **stack_b)
{
	int	size;

	size = get_list_size(*stack_a);
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size = get_list_size(*stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		calculate_costs(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	final_rotate(stack_a);
}
