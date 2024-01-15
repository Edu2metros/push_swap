/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/13 12:10:44 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_list(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (lstsize(*stack_a) == 1)
		return ;
	if (lstsize(*stack_a) < 4)
	{
		if (lstsize(*stack_a) == 2)
			sa(stack_a);
		else
			sort_three(stack_a);
	}
	else
	{
		if (lstsize(*stack_a) == 4 || lstsize(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		else
			radix(stack_a, stack_b, argc - 1);
	}
}

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
