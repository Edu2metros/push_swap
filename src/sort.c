/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/01 18:33:51 by eddos-sa         ###   ########.fr       */
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

/*     7, 2, 14 SA // menor valor estar no meio e valor medio estar em primeiro
	5, 8, 3 RRA // menor valor estar último e valor medio estar em primeiro
	12, 1, 9 RRA RRA -> 9 12 1 -> 1 9 12
		// menor valor estar no meio e valor medio estar em último
	15, 7, 3 ? RRA RRA SA // 3 15 7 -> 7 3 15 -> 3 7 15 //
	11, 6, 1 // RA RA SA
		// menor valor estar em último e valor médio estar no meio
*/

void sort_three(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *stack_a;
    second = (*stack_a)->next;
    third = (*stack_a)->next->next;

    if (first->number > second->number && second->number < third->number)
        swap(stack_a, "sa");
    else if (first->number > second->number && second->number > third->number)
    {
        swap(stack_a, "sa");
        reverse_rotate(stack_a, "rra");
    }
    else if (first->number > second->number && first->number < third->number)
        rotate(stack_a, "ra");
    else if (first->number < second->number && second->number > third->number)
    {
        if (first->number > third->number)
            reverse_rotate(stack_a, "rra");
        else
            swap(stack_a, "sa");
    }
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last;

	current = *stack_a;
	last = lstlast(*stack_a);
	ft_printf("lista com 4 ou 5 elemtos, em construção, volte depois\n");
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("função para mais de 5 elementos em construção, volte depois\n");
}
