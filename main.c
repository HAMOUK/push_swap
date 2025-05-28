/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:55:02 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/28 17:41:10 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

int     main(int argc, char **argv)
{
	t_stack		*stacka;
	t_stack		*stackb;
	int		check_parsing;

	stackb = NULL;
	if ((check_parsing = ft_parsing(argc, argv)) == 1)
	{	
		stacka = fill_stack(argc, argv);
		// Print stacka
		ft_printf(">>STACK A AVANT PUSH_SWAP<<\n");
		t_stack *tmp = stacka;
		while (tmp)
		{
			ft_printf("%d\n", tmp->content);
			tmp = tmp->next;
		}
		assign_index(stacka);
		radix(&stacka, &stackb);
		t_stack *tmp2 = stacka;
		ft_printf(">>STACK A APRES PUSH_SWAP<<\n");
		while (tmp2)
		{
			ft_printf("%d\n", tmp2->content);
			tmp2 = tmp2->next;
		}
	}
	return (0);
}