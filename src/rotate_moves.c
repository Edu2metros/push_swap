/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:43:46 by eduardo           #+#    #+#             */
/*   Updated: 2023/12/04 10:56:38 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **head, char *flag)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*head = (*head)->next;
	(*head)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	if (flag)
		ft_printf("%s\n", flag);
}

void	ra(t_stack **a)
{
	rotate(a, "ra");
}

void	rb(t_stack **b)
{
	rotate(b, "rb");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, "rr");
}
