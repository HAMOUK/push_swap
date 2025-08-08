/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silent_operation2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:37:28 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/08 16:40:54 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_ra(t_stack **stacka)
{
	t_stack	*tmp;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = NULL;
	ft_stack_add_back(stacka, tmp);
}
void	silent_rb(t_stack **stackb)
{
	t_stack *tmp;

	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = NULL;
	ft_stack_add_back(stackb, tmp);
}