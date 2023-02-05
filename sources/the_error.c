/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:22:50 by agimi             #+#    #+#             */
/*   Updated: 2023/02/03 12:33:15 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	the_error(char *path, char **com)
{
	int	i;

	i = -1;
	perror("pipex");
	if (path)
		free(path);
	if (com)
	{
		while (com[++i])
			free(com[i]);
		free(com);
	}
	if (errno == 13)
		exit (126);
	exit(127);
}

void	the_error1(char *path, char **com)
{
	int	i;

	i = -1;
	perror("pipex");
	if (path)
		free(path);
	if (com)
	{
		while (com[++i])
			free(com[i]);
		free(com);
	}
	exit(1);
}
