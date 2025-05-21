/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:50:39 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/20 15:19:16 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sb(t_stack *stackb)
{
	int		tmp;

    if (ft_stack_size(stackb) > 1)
	{
		tmp = stackb->content;
		stackb->content = stackb->next->content;
		stackb->next->content = tmp;
	}
	ft_printf("sb");
}

void    sa(t_stack *stacka)
{
	int		tmp;

    if (ft_stack_size(stacka) > 1)
	{
		tmp = stacka->content;
		stacka->content = stacka->next->content;
		stacka->next->content = tmp;
	}
	ft_printf("sa");
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (!stackb || !*stackb)
		return ;

	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = *stacka;
	*stacka = tmp;
	ft_printf("pa");
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (!stacka || !*stacka)
		return ;

	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = *stackb;
	*stackb = tmp;
	ft_printf("pb");
}