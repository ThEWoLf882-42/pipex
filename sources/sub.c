/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:07:12 by agimi             #+#    #+#             */
/*   Updated: 2023/01/27 20:21:23 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sub(char **com, char **env)
{
	char	*s;
	int		i;
	int		j;

	i = -1;
	while (com[++i])
	{
		j = -1;
		while (com[i][++j])
		{
			if (com[i][j] == '/')
			{
				s = ft_strjoin("./", com[i]);
				if (access(s, F_OK) == 0)
					if (access(s, X_OK) == 0)
						execve(s, com, env);
			}
		}
	}
}
