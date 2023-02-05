/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   musuko_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:19:47 by agimi             #+#    #+#             */
/*   Updated: 2023/02/05 17:11:26 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	musuko_bonus(char *argv, char **env, int fin, int i)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		the_error(NULL, NULL);
	pid = fork();
	if (pid == -1)
		the_error(NULL, NULL);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (fin == -1 && i == 2)
			exit (0);
		exe(argv, env);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
	}
}
