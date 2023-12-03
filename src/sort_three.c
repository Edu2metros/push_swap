/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:42:40 by eduardo           #+#    #+#             */
/*   Updated: 2023/12/03 19:42:44 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	first_smaller_than_second(t_stack **stack_a, int first, int third)
{
	if (third > first)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (third < first)
		rra(stack_a);
}

void	first_bigger_than_second(t_stack **stack_a, int second, int third)
{
	if (second > third)
	{
		rra(stack_a);
		rra(stack_a);
		sa(stack_a);
	}
	else if (second < third)
		sa(stack_a);
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
		first_smaller_than_second(stack_a, first, third);
	else
		first_bigger_than_second(stack_a, second, third);
}
