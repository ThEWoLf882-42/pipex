/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:23:23 by agimi             #+#    #+#             */
/*   Updated: 2023/02/03 12:47:31 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*loop(char **paths, char *com)
{
	char	*spath;
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		spath = ft_strjoin(paths[i], "/");
		path = ft_strjoin(spath, com);
		free(spath);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*path_find(char **com, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	i = -1;
	sub(com, env);
	if (!env[0])
		paths = ft_split("/Users/agimi/brew/bin:/Users/agimi/brew/bin:/Users/agimi/.brew/bin:\
			/Users/agimi/brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:\
			/Users/agimi/brew/bin:/Users/agimi/.brew/bin:./:/", ':');
	else
	{
		while (env[++i] && ft_strnstr(env[i], "PATH", 4) == 0)
			;
		if (!env[i])
			comand(com, "command not found");
		paths = ft_split(env[i] + 5, ':');
	}
	path = loop(paths, com[0]);
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	if (path)
		if (access(path, F_OK) == 0)
			return (path);
	return (0);
}
