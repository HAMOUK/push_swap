/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:25:29 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/20 16:30:24 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_digit(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int 	ft_parsing(int argc, char **argv)
{
	char	*string;
	int		i;

	i = 1;
	string = ft_strdup("");
	if (argc < 2)
		ft_printf("pas assez d'argument !\n");// checker cette conditon p/r au consignes
	else if (argc >= 2)
	{
		while (i < argc)
		{
			string = ft_strjoin(string, argv[i]);
			i++;
		}
		ft_printf(">>%s\n", string);
	}
	else
	{
		ft_printf("Erreur d'arguments\n");
		return (0);
	}
	if (check_digit(string) == -1)
	{
		ft_printf("l'argument est une string vide zebi\n");
	}
	else if (check_digit(string) == 0)
	{
		ft_printf("Un des arguments n'est pas un nombre !\n");
	}
	return (1);
}
