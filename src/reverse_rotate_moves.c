/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/04 10:56:12 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **head, char *flag)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = first;
	while (last->next != NULL)
		last = last->next;
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	*head = last;
	if (flag)
		ft_printf("%s\n", flag);
}

void	rra(t_stack **a)
{
	reverse_rotate(a, "rra");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b, "rrb");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, "rrr");
}
