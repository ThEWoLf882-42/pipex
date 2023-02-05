/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:28:23 by agimi             #+#    #+#             */
/*   Updated: 2023/02/05 17:46:08 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			the_error(NULL, NULL);
		pid = fork();
		if (pid == -1)
			the_error(NULL, NULL);
		if (pid == 0)
			musuko(argv, env, fd);
		oya(argv, env, fd);
		waitpid(pid, NULL, 0);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("synstax: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit(127);
	}
	return (0);
}
