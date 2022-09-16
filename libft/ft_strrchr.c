/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:48:38 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:48:48 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	res;

	res = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c % 256)
			res = i;
		i++;
	}
	if (str[i] == c % 256)
		res = i;
	if (res == -1)
		return (NULL);
	else
		return (&((char *)str)[res]);
}
