/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:08:18 by hlongin           #+#    #+#             */
/*   Updated: 2025/06/03 15:44:05 by hlongin          ###   ########.fr       */
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
void	dispatch_sort(t_stack **stacka, t_stack **stackb)
{
	int	size;

	size = ft_stack_size(*stacka);
	if (size == 2)
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size == 4)
		sort_four(stacka, stackb);
	else if (size == 5)
		sort_five(stacka, stackb);
	else if (size > 5)
		radix(stacka, stackb, size);
}
void	radix(t_stack **stacka, t_stack **stackb, int size)
{
	int		max_bits;
	int		i;
	int		j;

	i = 0;
	max_bits = 0;
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
