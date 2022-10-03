/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:25:32 by mseyitog          #+#    #+#             */
/*   Updated: 2022/10/03 17:53:41 by mseyitog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*one_more(char *str, int *size)
{
	char	*temp;
	int		i;

	i = -1;
	temp = (char *)malloc((*size + BUFFER_SIZE + 1) * sizeof(char));
	while(str[++i])
		temp[i] = str[i];
	temp[*size + BUFFER_SIZE] = 0;
	free(str);
	return(temp);
}

char	*import(char *src, char *dest, int *size)
{
	int	i;
	int	j;

	j = 0;
	i = *size;
	dest = one_more(dest, size);
	*size += BUFFER_SIZE;
	while (i < *size)
		dest[i++] = src[j++];
	return (dest);
}

int	is_nl(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return(1);
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return(0);
		++i;
	}
	return (1);
}

int	red_lenght(char	*red, char	del)
{
	int	i;

	i = 0;
	while (red[i] != del)
		++i;
	return(i + 1);
}

void	clear_red(char **red, int len)
{
	int		nullen;
	char	*new;
	int		i;

	i = 0;
	nullen = red_lenght(*red, '\0');
	new = (char *)malloc((nullen - len) * sizeof(char));
	while (i < nullen - len)
	{
		new[i] = (*red)[len + i];
		++i;
	}
	free(*red);
	*red = new;
}

char	*get_line(char **red)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = red_lenght(*red, '\n');
	ret = (char *)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		ret[i] = (*red)[i];
		i++;
	}
	ret[i] = 0;
	clear_red(red, len);
	return (ret);
}

char	*get_char(int fd)
{
	char		*get;
	static char *red;
	int			readsize;
	char		*ret;

	readsize = 0;
	get = (char *)malloc(BUFFER_SIZE * sizeof(char));
	
	while (is_nl(get) && read(fd, get, BUFFER_SIZE))
		red = import(get, red, &readsize);
	ret = get_line(&red);
	return (ret);
}