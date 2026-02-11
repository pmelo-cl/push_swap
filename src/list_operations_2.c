/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:20 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:39:38 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_doublelist	*find_min_node(t_doublelist *stack)
{
	t_doublelist	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	update_positions(t_doublelist **stack)
{
	t_doublelist	*current;
	int				pos;

	if (!stack || !*stack)
		return ;
	current = *stack;
	pos = 0;
	while (current)
	{
		current->index = pos;
		current = current->next;
		pos++;
	}
}

int	is_sorted(t_doublelist *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_list_size(t_doublelist *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
