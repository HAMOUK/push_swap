/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:55:02 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/26 16:03:05 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

int     main(int argc, char **argv)
{
	t_stack		*stacka;
	//t_stack		*stackb;
	int		check_parsing;

	//stackb = NULL;
	if ((check_parsing = ft_parsing(argc, argv)) == 1)
	{	
		stacka = fill_stack(argc, argv);
		// Print stacka
		t_stack *tmp = stacka;
		while (tmp)
		{
			ft_printf("%d\n", tmp->content);
			tmp = tmp->next;
		}
	}
	return (0);
}