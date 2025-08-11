/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:22:32 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 15:08:21 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_white_spaces(const char *s, int *i)
{
	while ((s[*i] >= 9 && s[*i] <= 13) || s[*i] == ' ')
		(*i)++;
}

int	parse_sign(const char *s, int *i)
{
	int		sign;

	sign = 1;
	if ((s[*i] == '-' || s[*i] == '+') && s[*i + 1] != '\0')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	would_overflow(long result, int digit, int sign)
{
	if (sign == 1)
		return (result > (INT_MAX - digit) / 10);
	return (result > (-(long)INT_MIN - digit) / 10);
}

int	ft_aatoi(const char *str, long *out)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	skip_white_spaces(str, &i);
	sign = parse_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (would_overflow(result, str[i] - '0', sign))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*out = result * sign;
	return (1);
}
