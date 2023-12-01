/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:51:46 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/01 14:21:50 by eddos-sa         ###   ########.fr       */
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
void				rotate(t_stack **head, char *flag);
void				reverse_rotate(t_stack **head, char *flag);

// PUSH FUNCTIONS
void				push_a(t_stack **stack_a, t_stack **stack_b, char *flag);

// SORT FUNCTIONS
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				sort_list(t_stack **stack_a, t_stack **stack_b);
t_stack				*lstlast(t_stack **last);
int					lstsize(t_stack *lst);
void				sort_three(t_stack **stack_a);
void				sort_more(t_stack **stack_a, t_stack **stack_b);

#endif