/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:59:22 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 14:15:45 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stacka, t_stack **stackb)
{
	silent_sa(stacka);
	silent_sb(stackb);
	ft_printf("ss\n");
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	silent_ra(stacka);
	silent_rb(stackb);
	ft_printf("rr\n");
}
