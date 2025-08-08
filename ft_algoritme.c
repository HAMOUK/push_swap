/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:08:18 by hlongin           #+#    #+#             */
/*   Updated: 2025/06/11 02:43:29 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_to_b(t_stack **stacka, t_stack **stackb, int chunk_max)
{
	// int		pushed;
	int		median;

	median = find_median_chunk(*stacka, chunk_max);
	// pushed = 0;
	while (has_chunk_element(*stacka, chunk_max))
	{
		if ((*stacka)->index <= chunk_max)
		{	
			pb(stacka, stackb);
			if ((*stackb)->index > median)
				rb(stackb);
			// pushed++;
		}
		else
			ra(stacka);
	}
}

void	push_back_to_a(t_stack **stacka, t_stack **stackb)
{
	int	max;

	while (*stackb)
	{
		max = find_max_index(*stackb);
		if (get_position(*stackb, max) <= ft_stack_size(*stackb) / 2)
		{
			while ((*stackb)->index != max)
				rb(stackb);
		}
		else
		{
			while ((*stackb)->index != max)
				rrb(stackb);
		}
		pa(stacka, stackb);
	}
}

void	sort_large(t_stack **stacka, t_stack **stackb)
{
	int		chunk_max;
	int		chunk_step;
	int		max_index;

	max_index = ft_stack_size(*stacka) - 1;
	if (ft_stack_size(*stacka) <= 100)
		chunk_step = 15;
	else
		chunk_step = 30;
	chunk_max = chunk_step - 1;
	while (chunk_max < max_index)
	{
		push_chunk_to_b(stacka, stackb, chunk_max);
		chunk_max += chunk_step;
	}
	push_chunk_to_b(stacka, stackb, chunk_max);
	push_back_to_a(stacka, stackb);
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
		sort_large(stacka, stackb);
}
/*void	radix(t_stack **stacka, t_stack **stackb, int size)
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
}*/
