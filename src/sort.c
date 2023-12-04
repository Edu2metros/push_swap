/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/04 15:06:49 by eddos-sa         ###   ########.fr       */
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
/*
Função que acha a posição do menor numero
CHega até o final
*/
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last;
	int		len;

	current = *stack_a;
	last = lstlast(*stack_a);
	len = lstsize(*stack_a) + 1;
	while(len-- > 2)
		pb(stack_a, stack_b);
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("função para mais de 5 elementos em construção, volte depois\n");
}
