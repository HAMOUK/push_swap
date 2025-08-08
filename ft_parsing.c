/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:25:29 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/08 12:22:01 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon(int *array, int size)
{
	int	i;
	int	j;

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

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	else if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*ft_parsing(int argc, char **argv)
{
	t_stack	*stacka;
	long	tmp;
	int		i;
	t_stack	*outer;
	t_stack	*inner;

	stacka = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
		{
			write(2, "Error\n", 6);
			if (stacka)
				free_stack(stacka);
			exit(EXIT_FAILURE);
		}
		if (!ft_aatoi(argv[i], &tmp))
		{
			write(2, "Error\n", 6);
			if (stacka)
				free_stack(stacka);
			exit(EXIT_FAILURE);
		}
		ft_stack_add_back(&stacka, ft_new_stack((int)tmp));
		i++;
	}
	outer = stacka;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->content == inner->content)
			{
				write(2, "Error\n", 6);
				if (stacka)
					free_stack(stacka);
				exit(EXIT_FAILURE);
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (stacka);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
