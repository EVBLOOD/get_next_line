/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:39:57 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/11 17:19:56 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) c == '\0' && s)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	int		count;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	k = ft_strlen(s2);
	count = i + k + 1;
	p = (char *) malloc(count * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	k = i;
	while (s1[k])
		p[i++] = s1[k++];
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *) malloc(ft_strlen(s) + 1);
	if (!p)
		return (0);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_getline(char *c)
{
	char	*end;
	int		i;
	
	i = 0;
	if (!c)
		return (NULL);
	while (c[i] && c[i] != '\n')
		i++;
	if (c[i] == '\n')
		i++;
	end = malloc((i + 1) * sizeof(char));
	if (!end)
	{
		free(c);
		return (NULL);
	}
	end[i] = '\0';
	while (--i >= 0)
		end[i] = c[i];
	return (end);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			res;
	char		*buf;

	if (fd < 0)
		return (NULL);
	save = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while ((res = read(fd, buf, BUFFER_SIZE)) || !ft_strchr(save, '\n'))
	{
		if (!save && res)
			save = ft_strdup(buf);
		else if (save && res)
			save = ft_strjoin(save, buf);
		free(buf);
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
		{
			free(save);
			return (NULL);
		}

	}
	line = ft_getline((char *) save);
	return (line);
}