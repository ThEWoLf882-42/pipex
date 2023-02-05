/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:20:32 by agimi             #+#    #+#             */
/*   Updated: 2023/02/03 12:21:13 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe(char *argv, char **env)
{
	char	**com;
	int		i;
	int		j;
	char	*path;

	i = -1;
	j = -1;
	while (argv[++j] == ' ')
		;
	if ((argv[j] == 'a' && argv[j + 1] == 'w' && argv[j + 2] == 'k')
		|| (argv[j] == 's' && argv[j + 1] == 'e' && argv[j + 2] == 'd'))
		awk(&argv[j], env);
	com = ft_split(argv, ' ');
	if (com[0][0] == '/' || com[0][0] == '.')
		full_p(com, env);
	path = path_find(com, env);
	if (!path)
	{
		comand(com, "command not found");
		while (com[++i])
			free(com[i]);
		free(com);
	}
	if (execve(path, com, env) == -1)
		the_error(path, com);
}
