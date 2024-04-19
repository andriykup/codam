/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:46:51 by ankupins          #+#    #+#             */
/*   Updated: 2024/03/17 11:46:53 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			three_node_sort(t_stack_node **stack);
bool			stack_sorted(t_stack_node *stack);
char			**st_split(char *str, char separator);
void			stack_init(t_stack_node **a, char **argv, bool argc_2);
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_last_node(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_cheapest(t_stack_node *b);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				value_check(char *str);
int				repetition_check(t_stack_node *a, int nbr);
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			move_nodes(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			free_stack(t_stack_node **stack);
void			free_memory(char **argv);
void			error_free(t_stack_node **a, char **argv, bool argc_2);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
