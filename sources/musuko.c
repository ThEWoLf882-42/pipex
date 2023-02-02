/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   musuko.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:37:42 by agimi             #+#    #+#             */
/*   Updated: 2023/02/02 13:29:45 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	musuko(char **argv, char **env, int *fd)
{
	int	fin;

	fin = open(argv[1], O_RDONLY);
	if (fin == -1)
		file(argv[1], 0);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fin, STDIN_FILENO);
	close(fd[0]);
	exe(argv[2], env);
}
