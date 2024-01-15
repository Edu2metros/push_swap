/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:41:11 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/12 13:57:44 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	define_index(t_stack *stack_a)
{
	unsigned int	index;
	t_stack			*current;
	t_stack			*aux;

	current = stack_a;
	index = 0;
	while (current)
	{
		aux = stack_a;
		while (aux)
		{
			if (current->number > aux->number)
				current->index++;
			aux = aux->next;
		}
		current = current->next;
	}
}

int	calculate_bits(int argc)
{
	int	count;

	count = 0;
	while (argc != 0)
	{
		argc = argc >> 1;
		count++;
	}
	return (count);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	len;

	index = 0;
	len = lstsize(*stack_b);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		index++;
	}
}

void	radix(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	bits;
	int	i;
	int	len_a;
	int	index;

	define_index(*stack_a);
	bits = calculate_bits(argc);
	len_a = lstsize(*stack_a);
	i = 0;
	while (i < bits)
	{
		index = 0;
		while (index < len_a)
		{
			if (((*stack_a)->index >> i) % 2 == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			index++;
		}
		push_a(stack_a, stack_b);
		i++;
	}
}
