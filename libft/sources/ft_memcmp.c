/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:11:36 by agimi             #+#    #+#             */
/*   Updated: 2023/02/02 15:11:37 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*as1;
	unsigned char	*as2;

	as1 = (unsigned char *)s1;
	as2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*as1 != *as2)
			return (*as1 - *as2);
		as1++;
		as2++;
		n--;
	}
	return (0);
}
