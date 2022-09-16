/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:35:20 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:35:47 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	else if (dest > src)
	{
		while (len > 0)
		{
			*((char *)(dest) + len - 1) = *((char *)(src) + len - 1);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *)(dest) + i) = *((char *)(src) + i);
			i++;
		}
	}
	return (dest);
}
