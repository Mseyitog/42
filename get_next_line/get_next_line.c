/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:01:20 by mseyitog          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:55 by mseyitog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	return (get_char(fd));
}

int main()
{
	char	*s;
	int fd = open("deneme.txt", O_RDONLY);

	s = get_next_line(fd);
	printf("%s",s);
	return (0);
}