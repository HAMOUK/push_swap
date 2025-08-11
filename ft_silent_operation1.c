/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silent_operation1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:32:58 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 14:05:46 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_rra(t_stack **stacka)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	tmp1 = *stacka;
	tmp2 = ft_stack_last(tmp1);
	while (tmp1->next != tmp2)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	tmp2->next = *stacka;
	*stacka = tmp2;
}

void	silent_rrb(t_stack **stackb)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	tmp1 = *stackb;
	tmp2 = ft_stack_last(tmp1);
	while (tmp1->next != tmp2)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	tmp2->next = *stackb;
	*stackb = tmp2;
}

void	silent_sa(t_stack **stacka)
{
	int	tmp;

	if (ft_stack_size(*stacka) > 1)
	{
		tmp = (*stacka)->content;
		(*stacka)->content = (*stacka)->next->content;
		(*stacka)->next->content = tmp;
	}
}

void	silent_sb(t_stack **stackb)
{
	int	tmp;

	if (ft_stack_size(*stackb) > 1)
	{
		tmp = (*stackb)->content;
		(*stackb)->content = (*stackb)->next->content;
		(*stackb)->next->content = tmp;
	}
}
