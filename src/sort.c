/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/06 19:01:02 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	if (lstsize(*stack_a) < 4)
	{
		if (lstsize(*stack_a) == 2)
			swap(stack_a, "sa");
		else
			sort_three(stack_a);
	}
	else
	{
		if (lstsize(*stack_a) == 4 || lstsize(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		else
			sort_more(stack_a, stack_b);
	}
}
// sortear 5 numero
// outro algoritimo q tire 100;

void	adjust_stacka(t_stack **stack_a, t_stack **stack_b)
{
	if (smallest_pos(*stack_a) == 0)
		pb(stack_a, stack_b);
	else if (smallest_pos(*stack_a) > 0 && smallest_pos(*stack_a) <= 2)
	{
		while (smallest_pos(*stack_a) != 0)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (smallest_pos(*stack_a) >= 2 && smallest_pos(*stack_a) <= 4)
	{
		while (smallest_pos(*stack_a) != 0)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	adjust_stacka(stack_a, stack_b);
	if (lstsize(*stack_a) == 4)
		adjust_stacka(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (lstsize(*stack_b) == 1)
		pa(stack_a, stack_b);
}

void push_b(t_stack **a, t_stack **b)
{
	int 
}

void push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	i = find_minor_value(*stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_a);
	while (lstsize(*stack_a) > 3)
		push_b(stack_a, stack_b);
	
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	push_stack_b(stack_a, stack_b);
}
