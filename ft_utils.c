/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:49:12 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 17:58:42 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stacka)
{
	t_stack	*current;
	t_stack	*compare;
	int		i;

	current = stacka;
	while (current)
	{
		i = 0;
		compare = stacka;
		while (compare)
		{
			if (current->content > compare->content)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

void	error(t_stack *stacka)
{
	write(2, "Error\n", 6);
	if (stacka)
		free_stack(stacka);
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r')
		return (1);
	else
		return (0);
}
