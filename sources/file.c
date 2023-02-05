/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:09:46 by agimi             #+#    #+#             */
/*   Updated: 2023/02/04 12:05:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file(char *f, int i)
{
	char	*t;

	t = ft_strjoin("pipex: ", f);
	t = ft_strjoin(t, ": No such file or directory\n");
	ft_putstr_fd(t, 2);
	if (i == 1)
		exit(0);
	exit(127);
}
