/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:08:53 by agimi             #+#    #+#             */
/*   Updated: 2023/01/16 17:36:07 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*an;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((char *)s1);
	an = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!an)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		an[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		an[i + j] = s2[j];
		j++;
	}
	an[i + j] = '\0';
	return (an);
}
