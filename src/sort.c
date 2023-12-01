/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/01 14:24:13 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack **stack_a)
{
	ft_printf("função para três elementos em construção, volte depois\n");
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last;

	current = *stack_a;
	last = lstlast(stack_a);
	ft_printf("lista com 4 ou 5 elemtos, em construção, volte depois\n");
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("função para mais de 5 elementos em construção, volte depois\n");
}
