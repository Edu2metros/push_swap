/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:49:05 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/30 16:49:28 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\n");
}

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
		current = new;
		i++;
	}
	return (value);
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

t_stack	*lstlast(t_stack **last)
{
	t_stack	*result;

	result = *last;
	while (result != NULL)
		result = result->next;
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		validate;

	stack_a = NULL;
	if (argc >= 3)
	{
		validate = check_args(argv);
		if (!validate)
			return (EXIT_SUCCESS);
		stack_a = init_stack_a(argv, stack_a);
		printlist(stack_a);
		sort_list(&stack_a, &stack_b);
		printlist(stack_a);
		free_stacks(&stack_a, &stack_b);
	}
}

/*
Fazer um algoritimo de ordenação de três números.
Fazer o push da stack a pra stack b
TErminar de fazer a ordenação de algorítimo, rrr,
	se tiver alguma flag imprimir aquilo etc
FAzer o bagulho de aceitar apenas um parametro se tiver ""
*/