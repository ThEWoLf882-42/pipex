/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:05:00 by agimi             #+#    #+#             */
/*   Updated: 2023/02/02 13:48:51 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	fin;
	int	fout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 2;
			fout = open_f(argv[argc - 1], 0);
			doc(argv[2], argc);
		}
		else
		{
			i = 1;
			fout = open_f(argv[argc - 1], 1);
			fin = open_f(argv[1], 2);
			dup2(fin, STDIN_FILENO);
		}
		while (++i < argc - 2)
			musuko_bonus(argv[i], env);
		dup2(fout, STDOUT_FILENO);
		exe(argv[argc - 2], env);
	}
	arggs();
}
