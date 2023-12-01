/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:11:07 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/01 17:47:39 by eddos-sa         ###   ########.fr       */
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
