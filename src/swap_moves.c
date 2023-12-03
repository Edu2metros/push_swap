/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:43:34 by eduardo           #+#    #+#             */
/*   Updated: 2023/12/03 19:43:35 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **head, char *flag)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->previous = first->previous;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	first->previous = second;
	*head = second;
	if (flag)
		ft_printf("%s\n", flag);
}

void	sa(t_stack **a)
{
	swap(a, "sa");
}

void	sb(t_stack **b)
{
	swap(b, "sb");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 0);
	swap(b, "ss");
}
