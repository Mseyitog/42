/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:25:32 by mseyitog          #+#    #+#             */
/*   Updated: 2022/10/09 17:24:46 by mseyitog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef NDEBUG
#include <stdio.h>
#endif

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	return (str);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = -1;
	while (*(s + ++i))
		;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(new_str + i++) = *(s2 + j);
	free(s1);
	return (new_str);
}

int	red_lenght(char	*red, char	del)
{
	int	i;

	i = 0;
	while (red[i] != del)
		++i;

	return(i + 1);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c % 256)
			return (&((char *)str)[i]);
		i++;
	}
	if (str[i] == c % 256 && c % 256 == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}

char	*clear_red(char **red, int len)
{
	int			nullen;
	char	*new;
	int			i;

	i = 0;
	nullen = red_lenght(*red, '\0');
	new = (char *)malloc((nullen - len) * sizeof(char));
	while (i < nullen - len)
	{
		new[i] = (*red)[len + i];
		++i;
	}
	new[i] = 0;
	free(*red);
	free(red);
	return(new);
}

char	*get_line(char **red)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = red_lenght(*red, '\n');
	line = (char *)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		line[i] = (*red)[i];
		i++;
	}
	line[i] = 0;
	*red = clear_red(red, len);
	return (line);
}

char	*get_char(int fd)
{
	char		*get;
	static char *red;
	int			sonuc;

	#ifndef NDEBUG
		printf("heyo");
	#endif
	sonuc = 1;
	get = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!get)
		return (0);
	while (!ft_strchr(get, '\n') && sonuc)
	{
		sonuc = read(fd, get, BUFFER_SIZE);
		if (sonuc == -1)
		{
			free(get);
			return (NULL);
		}
		get[BUFFER_SIZE] = 0;
		#ifndef NDEBUG
			printf("%s", get);
		#endif
		red = ft_strjoin(red, get);
	}
	#ifndef NDEBUG
			printf("bitti");
	#endif
	return (red);
}