/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:55:01 by mseyitog          #+#    #+#             */
/*   Updated: 2022/10/15 14:11:36 by mseyitog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*save[4096];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	save[fd] = read_file(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	ret = get_line(save[fd]);
	if (!save[fd][0])
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = clear_save(save[fd]);
	return (ret);
}

char	*clear_save(char *save)
{
	int			nullen;
	char		*new;
	int			i;
	int			len;

	i = 0;
	nullen = ft_strlen(save);
	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	new = malloc(((nullen - len) + 1) * sizeof(char));
	while (i < nullen - len)
	{
		new[i] = save[len + i + 1];
		++i;
	}
	new[i] = 0;
	free(save);
	return(new);
}

 char	*get_line(char *save)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!save[0])
		return (NULL);
	while (save[len] && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	if (len == 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*read_file(int fd, char *save)
{
	char		*buff;
	int			sonuc;

	sonuc = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	while (!ft_strchr(save, '\n') && sonuc != 0)
	{
		sonuc = read(fd, buff, BUFFER_SIZE);
		if (sonuc == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[sonuc] = 0;
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

/*  int main()
{
	char	*s;
	int fd = open("empty", O_RDONLY, 040);
	s = get_next_line(fd);
	while (s)
	{	
		printf("%s",s);
		s = get_next_line(fd);
	}
	return (0);
} 
 */