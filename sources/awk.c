/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:32:27 by agimi             #+#    #+#             */
/*   Updated: 2023/01/27 20:19:13 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	last_p(char *argv)
{
	int	i;

	i = ft_strlen(argv) + 1;
	while (argv[--i] != '\'' && argv[i] != '\"')
		;
	return (i);
}

char	**f_awk(char *argv)
{
	int		i;
	int		j;
	int		c;
	char	**r;

	i = 3;
	j = -1;
	c = last_p(argv);
	r = malloc(sizeof(char *) * 3);
	if (argv[++i] == '\'' || argv[i] == '\"')
		;
	if (argv[0] == 'a' && argv[1] == 'w' && argv[2] == 'k')
		r[0] = "awk";
	else if (argv[0] == 's' && argv[1] == 'e' && argv[2] == 'd')
		r[0] = "sed";
	while (argv[i] == ' ')
		i++;
	r[1] = malloc(sizeof(char) * (ft_strlen(&argv[i]) + 1));
	while (argv[++i] && i < c)
		r[1][++j] = argv[i];
	r[2] = NULL;
	return (r);
}

void	awk(char *argv, char **env)
{
	char	**com;
	char	*path;
	int		i;

	i = -1;
	com = f_awk(argv);
	path = path_find(com, env);
	if (!path)
	{
		comand(com[0], "command not found");
		while (com[++i])
			free(com[i]);
		free(com);
	}
	if (execve(path, com, env) == -1)
		the_error();
	exit(0);
}
