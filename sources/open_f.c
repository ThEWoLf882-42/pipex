/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:08:43 by agimi             #+#    #+#             */
/*   Updated: 2023/02/04 12:04:32 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_f(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		fd = open(argv, O_RDONLY);
	if (fd == -1 && i == 2)
		file(argv, 1);
	if (fd == -1 && i != 2)
		the_error1(NULL, NULL);
	return (fd);
}
