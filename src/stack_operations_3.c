/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:34 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:38:27 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_doublelist **a, int print_flag)
{
	t_doublelist	*last;
	t_doublelist	*second_last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	second_last = last->previous;
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	update_positions(a);
	if (print_flag)
		printf("rra\n");
}

void	rrb(t_doublelist **b, int print_flag)
{
	t_doublelist	*last;
	t_doublelist	*second_last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	second_last = last->previous;
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *b;
	(*b)->previous = last;
	*b = last;
	update_positions(b);
	if (print_flag)
		printf("rrb\n");
}

void	rrr(t_doublelist **a, t_doublelist **b)
{
	rra(a, 0);
	rrb(b, 0);
	printf("rrr\n");
}
