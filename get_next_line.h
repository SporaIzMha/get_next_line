/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:41:26 by marvin            #+#    #+#             */
/*   Updated: 2021/01/23 12:30:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *str, int ch);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strjoin(char *s1, char *s2);

#endif
