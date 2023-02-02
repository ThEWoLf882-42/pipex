/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:28:25 by agimi             #+#    #+#             */
/*   Updated: 2023/02/02 13:29:14 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

void	exe(char *argv, char **env);
void	musuko(char **argv, char **env, int *fd);
void	oya(char **argv, char **env, int *fd);
char	*path_find(char **com, char **env);
void	the_error(void);
void	the_error1(void);
void	comand(char *com, char *g);
void	full_p(char **com, char **env);
void	sub(char **com, char **env);
void	awk(char *argv, char **env);
void	file(char *f, int i);
int		open_f(char *argv, int i);
void	doc(char *l, int argc);
void	musuko_bonus(char *argv, char **env);
void	arggs(void);

#endif