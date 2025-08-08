/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 02:23:55 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/08 12:22:33 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int		max;
	t_stack	*current;

	current = stack;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int index)
{
	int		pos;
	t_stack	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (pos);
}
