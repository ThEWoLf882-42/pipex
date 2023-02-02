/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arggs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:29:06 by agimi             #+#    #+#             */
/*   Updated: 2023/02/02 13:25:53 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arggs(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> \
		<cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_FAILURE);
}
