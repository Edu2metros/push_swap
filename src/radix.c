/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:41:11 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/11 11:01:36 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printlist(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	ft_printf("stack a:\n");
	while (current_a != NULL)
	{
		ft_printf("number: %d | index: %d | pos: %d | target_pos: %d\n",
			current_a->number, current_a->index, current_a->pos,
			current_a->target_pos);
		current_a = current_a->next;
	}
	ft_printf("\nstack b:\n");
	while (current_b != NULL)
	{
		ft_printf("number: %d | index: %d | pos: %d | target_pos: %d\n",
			current_b->number, current_b->index, current_b->pos,
			current_b->target_pos);
		current_b = current_b->next;
	}
	ft_printf("\n");
}

int	calculate_bits(int argc)
{
	unsigned int	number_bits;
	int				number;

	number = argc - 2;
	number_bits = 0;
	while (number > 0)
	{
		number_bits++;
		number = number / 2;
	}
	return (number_bits);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	len;

	index = 0;
	len = lstsize(*stack_b);
	while (index < len)
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

	printlist(*stack_a, *stack_b);
	bits = calculate_bits(argc);
	len_a = lstsize(*stack_a);
	i = 0;
	while (i < bits)
	{
		index = 0;
		while (index < len_a)
		{
			if (((*stack_a)->number >> i) % 2 == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			index++;
		}
		push_a(stack_a, stack_b);
		i++;
	}
}
