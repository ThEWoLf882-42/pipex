/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:23:23 by agimi             #+#    #+#             */
/*   Updated: 2023/02/03 12:43:35 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	comand(char **com, char *g)
{
	int		i;
	char	*r;

	i = -1;
	r = ft_strjoin("pipex: ", com[0]);
	ft_putstr_fd(r, 2);
	free(r);
	r = ft_strjoin(": ", g);
	ft_putstr_fd(r, 2);
	free(r);
	ft_putstr_fd("\n", 2);
	while (com[++i])
		free(com[i]);
	free(com);
	exit(127);
}
