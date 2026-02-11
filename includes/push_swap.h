/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:10:13 by pmelo-cl          #+#    #+#             */
/*   Updated: 2026/02/04 15:10:37 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_doublelist
{
	int					value;
	int					index;
	int					cost_a;
	int					cost_b;
	struct s_doublelist	*next;
	struct s_doublelist	*previous;
}						t_doublelist;

t_doublelist			*create_node(int index, int value);
void					add_back(t_doublelist **head, t_doublelist *new);
void					add_front(t_doublelist **head, t_doublelist *new);
int						get_last_index(t_doublelist *head);
void					free_list(t_doublelist **head);
int						is_valid_number(char *str);
int						check_duplicates(t_doublelist *head);
void					process_argument(char *arg, t_doublelist **head,
							int *error);
void					normalize_arguments(int argc, char **argv,
							t_doublelist **head);
long					ft_atol(const char *str, int *error);
void					sa(t_doublelist **a);
void					sb(t_doublelist **b);
void					ss(t_doublelist **a, t_doublelist **b);
void					pa(t_doublelist **a, t_doublelist **b);
void					pb(t_doublelist **a, t_doublelist **b);
void					ra(t_doublelist **a, int print_flag);
void					rb(t_doublelist **b, int print_flag);
void					rr(t_doublelist **a, t_doublelist **b);
void					rra(t_doublelist **a, int print_flag);
void					rrb(t_doublelist **b, int print_flag);
void					rrr(t_doublelist **a, t_doublelist **b);
void					sort_two(t_doublelist **a);
void					sort_three(t_doublelist **a);
void					sort_four_five(t_doublelist **a, t_doublelist **b);
void					push_swap(t_doublelist **a, t_doublelist **b);
int						is_sorted(t_doublelist *stack);
int						get_list_size(t_doublelist *stack);
void					ft_putstr_fd(char *s, int fd);
int						ft_isdigit(int c);
char					**ft_split(char const *s, char c);
t_doublelist			*find_min_node(t_doublelist *stack);
void					update_positions(t_doublelist **stack);
int						get_node_position(t_doublelist *stack,
							t_doublelist *node);
void					greedy_sort(t_doublelist **stack_a,
							t_doublelist **stack_b);
int						get_min_position(t_doublelist *stack);
void					perform_moves(t_doublelist **stack_a,
							t_doublelist **stack_b, int cost_a, int cost_b);
void					free_split_from(char **split, int i);

#endif