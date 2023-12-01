/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:36 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/01 14:23:28 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b, char *flag)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack_a;
	last = *stack_b;
	ft_printf("%s\n", flag);
}
