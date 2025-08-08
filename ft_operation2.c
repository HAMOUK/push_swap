/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:53:50 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/08 12:21:21 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stacka)
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
	ft_printf("rra\n");
}

void	rrb(t_stack **stackb)
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
	ft_printf("rrb\n");
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka);
	rrb(stackb);
	ft_printf("rrr\n");
}

void	ra(t_stack **stacka)
{
	t_stack	*tmp;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = NULL;
	ft_stack_add_back(stacka, tmp);
	ft_printf("ra\n");
}

void	rb(t_stack **stackb)
{
	t_stack *tmp;

	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = NULL;
	ft_stack_add_back(stackb, tmp);
	ft_printf("rb\n");
}