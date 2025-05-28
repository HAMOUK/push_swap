/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:08:18 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/28 17:43:13 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stacka)
{
	t_stack		*current;
	t_stack		*compare;
	int		i;

	current = stacka;
	while (current)
	{
		i = 0;
		compare = stacka;
		while (compare)
		{
			if (current->content > compare->content )
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current ->next;
	}
}

void	radix(t_stack **stacka, t_stack **stackb)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;

	i = 0;
	max_bits = 0;
	size = ft_stack_size(*stacka);
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stacka)->index >> i) & 1) == 1)
				ra(stacka);
			else
				pb(stacka, stackb);
			j++;
		}
		while (*stackb)
			pa(stacka, stackb);
		i++;
	}
}
