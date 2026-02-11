/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:31 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:37:10 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_doublelist **a, int print_flag)
{
	t_doublelist	*first;
	t_doublelist	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	(*a)->previous = NULL;
	first->next = NULL;
	last->next = first;
	first->previous = last;
	update_positions(a);
	if (print_flag)
		printf("ra\n");
}

void	rb(t_doublelist **b, int print_flag)
{
	t_doublelist	*first;
	t_doublelist	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	(*b)->previous = NULL;
	first->next = NULL;
	last->next = first;
	first->previous = last;
	update_positions(b);
	if (print_flag)
		printf("rb\n");
}

void	rr(t_doublelist **a, t_doublelist **b)
{
	ra(a, 0);
	rb(b, 0);
	printf("rr\n");
}
