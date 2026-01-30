/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:18:01 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 15:00:46 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct t_stack	*next;
}					t_stack;

/* List Functions */
struct t_stack		*create_node(int x, int index);
struct t_stack		*insert_at_front(t_stack *head, int x);
struct t_stack		*insert_at_end(t_stack *head, int x);
void				print_list(t_stack *node);
struct t_stack		*insert_ordered(t_stack *head, int x);

/* push */
void				push(t_stack **from, t_stack **to);
void				pa(t_stack **lista, t_stack **listb);
void				pb(t_stack **lista, t_stack **listb);

/* rotate */
void				rotate(t_stack **head);
void				ra(t_stack **head);
void				rb(t_stack **head);
void				rr(t_stack **t_stack_a, t_stack **t_stack_b);

/* reverse rotate */
void				reverse_rotate(t_stack **head);
void				rra(t_stack **head);
void				rrb(t_stack **head);
void				rrr(t_stack **list_a, t_stack **list_b);

/* swap */
void				swap(t_stack **head);
void				sa(t_stack **head);
void				sb(t_stack **head);
void				ss(t_stack **t_stack_a, t_stack **t_stack_b);

/* handle input*/
void				free_inputs(char **inputs);
char				**handle_input(char *argv);
int					is_int(const char *argv);
// int is_double(char **argv);
int					parse_input(int argc, char **argv, t_stack **a);
int					parse_error(t_stack **a, char **tokens);

/* sort */
int					is_sorted(t_stack *a);
void				sort_3(t_stack **a);
void				sort_5(t_stack **a, t_stack **b);

/* algo */
void				leave_3_in(t_stack **a, t_stack **b);
void				final_rotate(t_stack **a);
void				assign_index(t_stack *stack);
int					get_target_pos(t_stack *a, int b_index);
void				calculate_cost(t_stack *a, t_stack *b);
t_stack				*find_cheapest(t_stack *b);
void				execute_move(t_stack **a, t_stack **b, int cost_a,
						int cost_b);
void				set_position(t_stack *stack);
void				turk_sort(t_stack **a, t_stack **b);
void				assign_target_pos(t_stack *a, t_stack *b);
void				rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);

/* helpers */
void				free_t_stack(t_stack **s);
int					contains_value(t_stack *a, int v);
int					get_stack_size(t_stack *stack);
int					find_min_value(t_stack *stack);
int					find_min_index(t_stack *stack);
int					overflow_next(long acc, int digit, long limit);
int					parse_sign(const char *s, int *i, int *sign, long *limit);
int					safe_atoi(const char *s, int *out);

#endif