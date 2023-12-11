/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/11 10:58:34 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_variables(t_stack *aux)
{
	aux->index = 0;
	aux->pos = 0;
	aux->target_pos = 0;
	aux->cost_a = 0;
	aux->cost_b = 0;
}

void	define_index(t_stack *stack_a, int size)
{
	int		value;
	t_stack	*ptr;
	t_stack	*high;

	while (--size > 0)
	{
		ptr = stack_a;
		value = INTMIN;
		high = NULL;
		while (ptr)
		{
			if (ptr->number == INTMIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->number > value && ptr->index == 0)
			{
				value = ptr->number;
				high = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (high != NULL)
			high->index = size;
	}
}

void	define_tag_pos(t_stack *b, t_stack *a)
{
	t_stack	*current_b;

	while (a != NULL)
	{
		current_b = b;
		while (current_b != NULL)
		{
			if (current_b->index + 1 == a->index || current_b->index
				- 1 == a->index)
			{
				current_b->target_pos = a->pos;
				break ;
			}
			current_b = current_b->next;
		}
		a = a->next;
	}
}

void	define_pos(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = stack_a;
	i = 0;
	while (current_a != NULL)
	{
		current_a->pos = i;
		current_a = current_a->next;
		i++;
	}
	current_b = stack_b;
	i = 0;
	while (current_b != NULL)
	{
		current_b->pos = i;
		current_b = current_b->next;
		i++;
	}
	define_tag_pos(stack_b, stack_a);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	init_variables(*stack_a);
	define_index(*stack_a, lstsize(*stack_a) + 1);
	while (lstsize(*stack_a) != 5)
		pb(stack_a, stack_b);
	sort_five(stack_a, stack_b);
	define_pos(*stack_a, *stack_b);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (lstsize(*stack_a) < 4)
	{
		if (lstsize(*stack_a) == 2)
			swap(stack_a, "sa");
		else
			sort_big(stack_a, stack_b);
	}
	else
	{
		if (lstsize(*stack_a) == 4 || lstsize(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		else
			sort_big(stack_a, stack_b);
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
