/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:41:11 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/07 14:46:50 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printlist(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*current2;

	current = stack_a;
	ft_printf("stack a: ");
	while (current != NULL)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\n");
	ft_printf("stack b ");
	current2 = stack_b;
	while (current2 != NULL)
	{
		ft_printf("%d ", current2->number);
		current2 = current2->next;
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
