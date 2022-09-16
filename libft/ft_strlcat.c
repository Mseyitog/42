/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:44:17 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:44:35 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;
	size_t	value;

	i = 0;
	size = 0;
	while (dst[size])
		size++;
	if (dstsize > (size_t)ft_strlen(dst))
		value = (size_t)ft_strlen(dst) + (size_t)ft_strlen(src);
	else
		return (dstsize + ft_strlen(src));
	while (src[i] && size < dstsize - 1)
	{
		dst[size] = src[i];
		size++;
		i++;
	}
	if (dstsize)
		dst[size] = 0;
	return (value);
}
