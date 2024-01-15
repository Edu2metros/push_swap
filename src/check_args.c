/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:53:06 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/12/13 12:13:37 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_limits(const char *str)
{
	long int	num;

	if (str == NULL || *str == '\0' || !ft_isalldigit(str))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	is_ordened(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!ft_limits(argv[i]))
			return (0);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
