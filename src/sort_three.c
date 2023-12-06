/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:56:27 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/06 13:20:28 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	first_smaller_than_second(t_stack **stack_a, int first, int second,
		int third)
{
	if (first < third && second > third)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (first > third && second > third)
		rra(stack_a);
}

void	first_bigger_than_second(t_stack **stack_a, int first, int second,
		int third)
{
	ft_printf("entrou\n");
	if (first < third && second < third)
		sa(stack_a);
	else if (first > third && second < third)
		ra(stack_a);
	else if (first > third && second > third)
	{
		ra(stack_a);
		sa(stack_a);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (first < second)
		first_smaller_than_second(stack_a, first, second, third);
	else
		first_bigger_than_second(stack_a, first, second, third);
}