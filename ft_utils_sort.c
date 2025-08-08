/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:40 by hlongin           #+#    #+#             */
/*   Updated: 2025/06/04 00:01:32 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack **stacka)
{
	t_stack		*current;
	t_stack		*compare;

	current = *stacka;
	compare = current->next;
		if (current-> content > compare->content)
			sa(stacka);
}

void	sort_three(t_stack **stacka)
{
	int			a;
	int			b;
	int			c;

	a = (*stacka)->index;
	b = (*stacka)->next->index;
	c = (*stacka)->next->next->index;

	if (a > b && b < c && a < c)
		sa(stacka);
	else if (a > b && b > c)
	{
		sa(stacka);
		rra(stacka);
	}
	else if (a > b && b < c && a > c)
		ra(stacka);
	else if (a < b && b > c && a < c)
	{
		sa(stacka);
		ra(stacka);
	}
	else if (a < b && b > c && a > c)
		rra(stacka);
}  

void	sort_four(t_stack **stacka, t_stack **stackb)
{
	t_stack		*tmp;
	int  		pos;

	pos = 0;
	tmp = *stacka;
	while (tmp && tmp->index != 0)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos == 1)
		ra(stacka);
	else if (pos == 2)
	{	
		rra(stacka);
		rra(stacka);
	}
	else if (pos == 3)
		rra(stacka);
	pb(stacka, stackb);
	sort_three(stacka);
	pa(stacka, stackb);
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	int	pos;

	pos = find_pos(*stacka, 0);
	while (pos-- > 0)
		ra(stacka);
	pb(stacka, stackb);
	pos = find_pos(*stacka, 1);
	while (pos-- > 0)
		ra(stacka);
	pb(stacka, stackb);
	sort_three(stacka);
	if ((*stackb)->index < (*stackb)->next->index)
		sb(stackb);
	pa(stacka, stackb);
	pa(stacka, stackb);
}
int		find_pos(t_stack *tmp, int target)
{
	int		pos;

	pos = 0;
	while (tmp && tmp->index != target)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}