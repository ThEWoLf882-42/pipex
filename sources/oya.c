/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oya.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:37:02 by agimi             #+#    #+#             */
/*   Updated: 2023/01/16 15:54:08 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	oya(char **argv, char **env, int *fd)
{
	int	fout;

	fout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fout == -1)
		the_error1(NULL, NULL);
	dup2(fd[0], STDIN_FILENO);
	dup2(fout, STDOUT_FILENO);
	close(fd[1]);
	exe(argv[3], env);
}
