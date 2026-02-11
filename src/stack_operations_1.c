/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:28 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:38:35 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_doublelist **a, t_doublelist **b)
{
	t_doublelist	*first_b;

	if (!*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	if (*b)
		(*b)->previous = NULL;
	first_b->next = *a;
	if (*a)
		(*a)->previous = first_b;
	*a = first_b;
	update_positions(a);
	update_positions(b);
	printf("pa\n");
}

void	pb(t_doublelist **a, t_doublelist **b)
{
	t_doublelist	*first_a;

	if (!*a)
		return ;
	first_a = *a;
	*a = first_a->next;
	if (*a)
		(*a)->previous = NULL;
	first_a->next = *b;
	if (*b)
		(*b)->previous = first_a;
	*b = first_a;
	update_positions(a);
	update_positions(b);
	printf("pb\n");
}

void	sa(t_doublelist **a)
{
	t_doublelist	*first;
	t_doublelist	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*a = second;
	update_positions(a);
	printf("sa\n");
}

void	sb(t_doublelist **b)
{
	t_doublelist	*first;
	t_doublelist	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*b = second;
	update_positions(b);
	printf("sb\n");
}

void	ss(t_doublelist **a, t_doublelist **b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}
