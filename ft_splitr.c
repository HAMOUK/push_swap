/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:07 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 17:49:19 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_tab(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_word(const char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (word);
}

char	*ft_strdupcustom(const char *start, const char *end)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = end - start;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = *start;
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	skip_and_set(const char **s, int *i, const char **start)
{
	while (ft_isspace((*s)[*i]))
		(*i)++;
	*start = &(*s)[*i];
	while ((*s)[*i] && !ft_isspace((*s)[*i]))
		(*i)++;
}

char	**ft_splitr(const char *s)
{
	int				word;
	int				i;
	int				ligne;
	const char		*start;
	char			**tab;

	i = 0;
	ligne = 0;
	word = count_word(s);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	while (ligne < word)
	{
		skip_and_set(&s, &i, &start);
		tab[ligne] = ft_strdupcustom(start, &s[i]);
		if (!tab[ligne])
		{
			free_tab(tab, ligne);
			return (NULL);
		}
		ligne++;
	}
	tab[ligne] = NULL;
	return (tab);
}
