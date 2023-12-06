/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:51:46 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/06 17:44:54 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define INTMIN -2147483648
# define INTMAX 2147483647

typedef struct s_stack
{
	int				number;

	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// CHECK_ARGS FUNCTIONS

int					ft_limits(const char *str);
int					is_ordened(char **argv);
int					check_args(char **argv);

// FREE FUNCTIONS

void				free_stack_b(t_stack **stack);
void				free_stack_a(t_stack **stack);
int					free_stacks(t_stack **stack_a, t_stack **stack_b);

// MOVES FUNCTIONS

void				swap(t_stack **head, char *flag);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				rotate(t_stack **head, char *flag);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				reverse_rotate(t_stack **head, char *flag);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// PUSH FUNCTIONS
void				push(t_stack **stack_receive, t_stack **stack_to_send,
						char *flag);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

// SORT FUNCTIONS
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				sort_list(t_stack **stack_a, t_stack **stack_b);
t_stack				*lstlast(t_stack *last);
int					lstsize(t_stack *lst);
void				sort_three(t_stack **stack_a);
void				sort_more(t_stack **stack_a, t_stack **stack_b);
void				printlist(t_stack *stack_a, t_stack *stack_b);
int					smallest_pos(t_stack *stack);
int					second_smallest_pos(t_stack *stack);
int					biggest_pos(t_stack *stack);

#endif