/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:55:02 by hlongin           #+#    #+#             */
/*   Updated: 2025/06/03 15:43:32 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

int		is_sorted(t_stack *stacka)
{
	while (stacka && stacka->next)
	{
		if (stacka->content > stacka->next->content)
			return (0);
		stacka = stacka->next;
	}	
	return (1);
}

int     main(int argc, char **argv)
{
	t_stack		*stacka;
	t_stack		*stackb;

	stackb = NULL;
	stacka = ft_parsing(argc, argv);
	/*// Print stacka
	ft_printf(">>STACK A AVANT PUSH_SWAP<<\n");
	t_stack *tmp = stacka;
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}*/
	if (is_sorted(stacka))
	{
		free_stack(stacka);
		return (0);
	}
	assign_index(stacka);
	dispatch_sort(&stacka, &stackb);
	/*t_stack *tmp2 = stacka;
	ft_printf(">>STACK A APRES PUSH_SWAP<<\n");
	while (tmp2)
	{
		ft_printf("%d\n", tmp2->content);
		tmp2 = tmp2->next;
	}*/
	free_stack(stacka);
	if (stackb)
		free_stack(stackb);
	return (0);
}