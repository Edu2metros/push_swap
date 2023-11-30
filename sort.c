/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/30 18:22:58 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// tá o que eu faço agora? 6 3 0 5 -2
void	sort_three(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;

	current = *stack;
	last = lstlast(stack);
	if(current->number > current->next->number)
		swap(stack, "sa");
	// if(last->number < current->number)
	// 	reverse_rotate(stack, "rra");
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	if (lstsize(*stack_a) == 3)
		sort_three(stack_a);
}

t_stack	*lstlast(t_stack **stack)
{
	t_stack	*result;

	result = *stack;
	while (result != NULL && result->next != NULL)
		result = result->next;
	return (result);
}


int	lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
