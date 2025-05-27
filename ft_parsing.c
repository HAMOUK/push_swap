/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:25:29 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/26 16:02:42 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_doublon(int *array, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_digit(char *str)
{
	int		i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int 	ft_parsing(int argc, char **argv)
{
	int	*stacka; 
	int		i;
	long	tmp;

	i = 1;
	if (argc < 2)
	{
		ft_printf(">>Pas assez d'arguments !\n");
		return (0);
	}
	stacka = (int *)malloc(sizeof (int) * (argc - 1));
	if (!stacka)
		return (0);
	while (i < argc)
	{
		if (!check_digit(argv[i]))
		{
			ft_printf(">>L'argument n'est pas un nombre !\n");
			free(stacka);
			return (0);
		}
		tmp = ft_aatoi(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			ft_printf(">>Valeur hors limite !\n");
			free(stacka);
			return (0);
		}
		stacka[i - 1] = (int)tmp;
		i++;
	}
	if (!check_doublon(stacka, (argc - 1)))
	{
		ft_printf(">>Il y'a des doublons !\n");
		free(stacka);
		return (0);
	}
	free(stacka);
	return (1);
}
