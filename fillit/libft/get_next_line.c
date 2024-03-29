/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:01:20 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/29 12:57:15 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*chek_str(char *str, char **line)
{
	char *p;

	p = NULL;
	if (str)
	{
		if ((p = ft_strchr(str, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(str);
			p++;
			ft_strcpy(str, p);
		}
		else
		{
			*line = ft_strdup(str);
			ft_strclr(str);
		}
	}
	else
		*line = ft_strnew(1);
	return (p);
}

static void		find_n(char *p, char **str)
{
	char *tmp;

	*p = '\0';
	p++;
	tmp = *str;
	*str = ft_strdup(p);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buf[BUFF_SIZE + 1];
	int			d;
	char		*p;
	char		*tmp;

	if (fd < 0 || !line || fd > 10240 ||
			read(fd, buf, 0) == -1 || BUFF_SIZE < 1)
		return (-1);
	d = 1;
	p = chek_str(str, line);
	while (!p && (d = read(fd, buf, BUFF_SIZE)))
	{
		buf[d] = '\0';
		if ((p = ft_strchr(buf, '\n')))
			find_n(p, &str);
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || d < 0)
			return (-1);
		free(tmp);
	}
	return ((d || ft_strlen(*line)) ? 1 : 0);
}
