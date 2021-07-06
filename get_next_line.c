/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:41:10 by marvin            #+#    #+#             */
/*   Updated: 2021/01/23 12:33:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_strclr(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static char			*ft_strnew(int i)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

static char			*check_rem_line(char **rem_line, char **line)
{
	char			*p;

	p = NULL;
	*line = NULL;
	if (*rem_line != NULL)
	{
		if ((p = ft_strchr(*rem_line, '\n')))
		{
			*p = '\0';
			p++;
			*line = ft_strdup(*rem_line);
			if (*p)
				ft_strcpy(*rem_line, p);
			else
				ft_strclr(&*rem_line);
		}
		else
		{
			*line = ft_strdup(*rem_line);
			ft_strclr(&*rem_line);
		}
	}
	else
		*line = ft_strnew(0);
	return (p);
}

int					get_next_line(int fd, char **line)
{
	char			*tmp;
	char			*p;
	int				i;
	static char		*rem_line[10000];

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
		!(tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) ||
		(read(fd, tmp, 0)) < 0)
		return (-1);
	p = check_rem_line(&rem_line[fd], line);
	while ((!p) && (i = read(fd, tmp, BUFFER_SIZE)))
	{
		tmp[i] = '\0';
		if ((p = ft_strchr(tmp, '\n')))
		{
			*p = '\0';
			p++;
			if ((*p) && !(rem_line[fd] = ft_strdup(p)))
				return (-1);
		}
		if (!(*line = ft_strjoin(*line, tmp)))
			return (-1);
	}
	free(tmp);
	return (p ? 1 : 0);
}
