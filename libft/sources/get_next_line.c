/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:23:08 by agimi             #+#    #+#             */
/*   Updated: 2023/02/05 19:17:02 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_n(char *naah, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!naah)
	{
		naah = (char *)malloc(1 * sizeof(char));
		naah[0] = '\0';
	}
	if (!naah || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(naah) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (naah)
		while (naah[++i] != '\0')
			str[i] = naah[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(naah) + ft_strlen(buff)] = '\0';
	free(naah);
	return (str);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
