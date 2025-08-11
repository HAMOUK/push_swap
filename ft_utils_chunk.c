/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 02:22:35 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 14:15:09 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_chunk_array(t_stack *stacka, int chunk_max, int *array)
{
	int		i;
	t_stack	*current;

	current = stacka;
	i = 0;
	while (current)
	{
		if (current->index <= chunk_max)
			array[i++] = current->index;
		current = current->next;
	}
	return (i);
}

int	find_median_chunk(t_stack *stacka, int chunk_max)
{
	int		*array;
	int		size_chunk;
	int		median;
	t_stack	*current;

	current = stacka;
	size_chunk = 0;
	while (current)
	{
		if (current->index <= chunk_max)
			size_chunk++;
		current = current->next;
	}
	array = (int *)malloc(sizeof(int) * size_chunk);
	if (!array)
		exit(EXIT_FAILURE);
	fill_chunk_array(stacka, chunk_max, array);
	bubble_sort(array, size_chunk);
	median = array[size_chunk / 2];
	free(array);
	return (median);
}

int	has_chunk_element(t_stack *stacka, int chunk_max)
{
	t_stack	*current;

	current = stacka;
	while (current)
	{
		if (current->index <= chunk_max)
			return (1);
		current = current->next;
	}
	return (0);
}
