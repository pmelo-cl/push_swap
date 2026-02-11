/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:26:16 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 14:58:45 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_index(t_doublelist *head)
{
	if (head == NULL)
		return (-1);
	while (head->next != NULL)
		head = head->next;
	return (head->index);
}

void	free_list(t_doublelist **head)
{
	t_doublelist	*tmp;
	t_doublelist	*next;

	if (!head || !*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}

int	get_min_position(t_doublelist *stack)
{
	t_doublelist	*min_node;
	int				min_pos;

	min_node = find_min_node(stack);
	min_pos = min_node->index;
	return (min_pos);
}
