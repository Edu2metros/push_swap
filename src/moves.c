/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:55 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/01 18:00:28 by eddos-sa         ###   ########.fr       */
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
	ft_printf("%s\n", flag);
}

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
