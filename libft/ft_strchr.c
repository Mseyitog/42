/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:42:07 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:42:22 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
