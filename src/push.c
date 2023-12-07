/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:36 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/07 12:41:41 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack_b(t_stack *stack_b, int value)
{
	t_stack	*current;

	current = NULL;
	stack_b = ft_calloc(1, sizeof(t_stack));
	stack_b->number = value;
	stack_b->next = NULL;
	stack_b->previous = NULL;
	return (stack_b);
}

void	push(t_stack **src, t_stack **dst, char *flag)
{
	t_stack	*aux;

	if (!src || !dst)
		return ;
	aux = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	aux->next = *dst;
	if (*dst)
		(*dst)->previous = aux;
	*dst = aux;
	(*dst)->previous = NULL;
	ft_printf("%s\n", flag);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a, "pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, "pb");
}
