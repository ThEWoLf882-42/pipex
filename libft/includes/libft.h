/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:06:07 by agimi             #+#    #+#             */
/*   Updated: 2023/02/02 15:13:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		get_next_line(char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif