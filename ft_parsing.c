/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:25:29 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 17:44:06 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon(t_stack *stacka)
{
	t_stack	*outer;
	t_stack	*inner;

	outer = stacka;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->content == inner->content)
				error(stacka);
			inner = inner->next;
		}
		outer = outer->next;
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

void	add_split_to_stack(t_stack **stacka, char **split)
{
	int		j;
	long	tmp;

	j = 0;
	while (split[j])
	{
		if (!check_digit(split[j]))
			error(*stacka);
		if (!ft_aatoi(split[j], &tmp))
			error(*stacka);
		ft_stack_add_back(stacka, ft_new_stack((int)tmp));
		j++;
	}
}

t_stack	*ft_parsing(int argc, char **argv)
{
	t_stack	*stacka;
	int		i;
	char	**split;

	stacka = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		split = ft_splitr(argv[i]);
		if (!split)
			error(stacka);
		add_split_to_stack(&stacka, split);
		free_split(split);
		i++;
	}
	check_doublon(stacka);
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
