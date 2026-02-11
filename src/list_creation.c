/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:13 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:37:34 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_doublelist	*create_node(int index, int value)
{
	t_doublelist	*new;

	new = malloc(sizeof(t_doublelist));
	if (!new)
		return (NULL);
	new->index = index;
	new->value = value;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	add_back(t_doublelist **head, t_doublelist *new)
{
	t_doublelist	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
}

void	add_front(t_doublelist **head, t_doublelist *new)
{
	if (!*head)
	{
		*head = new;
		return ;
	}
	new->next = *head;
	(*head)->previous = new;
	*head = new;
}
