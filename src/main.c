/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:05 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/13 12:13:30 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack_a(char **argv, t_stack *value)
{
	t_stack	*current;
	t_stack	*new;
	int		i;
	int		val;

	value = ft_calloc(1, sizeof(t_stack));
	current = value;
	i = 1;
	value->number = ft_atoi(argv[i]);
	value->next = NULL;
	value->previous = NULL;
	i++;
	while (argv[i] != NULL)
	{
		new = (t_stack *)ft_calloc(1, sizeof(t_stack));
		val = ft_atoi(argv[i]);
		new->number = val;
		new->next = NULL;
		current->next = new;
		new->previous = current;
		new->index = 0;
		current = new;
		i++;
	}
	return (value);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		validate;

	stack_a = NULL;
	stack_b = NULL;
	validate = 0;
	if (argc > 1)
	{
		if (!check_args(argv))
			return (EXIT_FAILURE);
		if (!is_ordened(argv))
			return (EXIT_SUCCESS);
		stack_a = init_stack_a(argv, stack_a);
		sort_list(&stack_a, &stack_b, argc);
		free_stacks(&stack_a, &stack_b);
	}
	return (EXIT_SUCCESS);
}
