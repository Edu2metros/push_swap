/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:11:07 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/06 12:31:41 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_ordened_list(t_stack *head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

t_stack	*lstlast(t_stack *stack)
{
	t_stack	*result;

	result = stack;
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

int	smallest_pos(t_stack *stack)
{
	int	pos;
	int	i;
	int	min;

	pos = 0;
	i = 0;
	min = stack->number;
	while (stack != NULL)
	{
		if (stack->number < min)
		{
			min = stack->number;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	biggest_pos(t_stack *stack)
{
	int	pos;
	int	i;
	int	max;

	pos = 0;
	i = 0;
	max = stack->number;
	while (stack != NULL)
	{
		if (stack->number > max)
		{
			max = stack->number;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	second_smallest_pos(t_stack *stack)
{
	int	pos;
	int	i;
	int	max;
	int	second_max;

	pos = 0;
	i = 0;
	max = INTMAX;
	second_max = INTMAX;
	while (stack != NULL)
	{
		if (stack->number < max)
		{
			second_max = max;
			max = stack->number;
			pos = i;
		}
		else if (stack->number < second_max && stack->number != max)
		{
			second_max = stack->number;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
