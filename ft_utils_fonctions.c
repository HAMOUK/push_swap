/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:22:32 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/26 16:12:48 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_aatoi(const char *str)
{
	int	i;
	int	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return ((long)INT_MAX + 1);
		if (sign == -1 && -result < INT_MIN)
			return ((long)INT_MIN - 1);
		i++;
	}
	return (result * sign);
}
t_stack		*fill_stack(int argc, char **argv)
{
	t_stack		*stacka = NULL;
	int		i;
	int		nbr;

	i = 1;
	while (i < argc)
	{
		nbr = ft_aatoi(argv[i]);
		ft_stack_add_back(&stacka, ft_new_stack(nbr));
		i++;
	}
	return (stacka);
}