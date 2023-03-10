/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:28:25 by agimi             #+#    #+#             */
/*   Updated: 2023/02/05 17:36:06 by agimi            ###   ########.fr       */
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
void	the_error(char *path, char **com);
void	the_error1(char *path, char **com);
void	comand(char **com, char *g);
void	full_p(char **com, char **env);
void	sub(char **com, char **env);
void	awk(char *argv, char **env);
void	file(char *f);
int		open_f(char *argv, int i);
void	doc(char *l, int argc);
void	musuko_bonus(char *argv, char **env, int fin, int i);
void	arggs(void);

#endif