/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:35 by agimi             #+#    #+#             */
/*   Updated: 2023/02/03 12:27:09 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	full_p(char **com, char **env)
{
	int		i;

	i = -1;
	if (access(com[0], F_OK) == 0)
		if (execve(com[0], com, env) == -1)
			the_error(NULL, com);
	comand(com, "no such file or directory: ");
}
