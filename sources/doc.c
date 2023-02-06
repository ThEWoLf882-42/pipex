/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:13:53 by agimi             #+#    #+#             */
/*   Updated: 2023/02/05 19:18:01 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	doc(char *l, int argc)
{
	int		fd[2];
	pid_t	pidr;
	char	*line;

	if (argc < 6)
		arggs();
	if (pipe(fd) == -1)
		the_error(NULL, NULL);
	pidr = fork();
	if (pidr == 0)
	{
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, l, ft_strlen(l)) == 0)
				exit(0);
			ft_putstr_fd((line), fd[1]);
		}
	}
	else
	{
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
	}
	close(fd[0]);
	close(fd[1]);
}
