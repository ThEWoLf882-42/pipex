/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:24 by agimi             #+#    #+#             */
/*   Updated: 2023/01/22 17:30:45 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	aw;
	size_t	i;

	aw = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			aw++;
		i++;
	}
	return (aw);
}

static void	fill_tab(char *new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

static void	set_mem(char **tab, char const *s, char c)
{
	size_t	ac;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		ac = 0;
		while (s[index + ac] && s[index + ac] != c)
			ac++;
		if (ac > 0)
		{
			tab[i] = malloc(sizeof(char) * (ac + 1));
			if (!tab[i])
				return ;
			fill_tab(tab[i], (s + index), c);
			i++;
			index = index + ac;
		}
		else
			index++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	aw;
	char	**ata;

	if (!s)
		return (NULL);
	aw = count_words(s, c);
	ata = malloc(sizeof(char *) * (aw + 1));
	if (!ata)
		return (NULL);
	set_mem(ata, s, c);
	return (ata);
}
