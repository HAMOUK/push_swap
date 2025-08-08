/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:55:02 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/08 16:01:54 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/ft_printf.h"
#include "push_swap.h"

int	is_sorted(t_stack *stacka)
{
	while (stacka && stacka->next)
	{
		if (stacka->content > stacka->next->content)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *stacka;
	t_stack *stackb;

	stackb = NULL;
	stacka = ft_parsing(argc, argv);
	if (is_sorted(stacka))
	{
		free_stack(stacka);
		return (0);
	}
	assign_index(stacka);
	dispatch_sort(&stacka, &stackb);
	/* while (stacka)
	{
		ft_printf("%d\n", stacka->content);
		stacka = stacka->next;
	} */
	free_stack(stacka);
	if (stackb)
		free_stack(stackb);
	return (0);
}