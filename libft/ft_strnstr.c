/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:47:58 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:53:23 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	find(const char *haystack, const char *needle,
		size_t len, size_t hay_len)
{
	size_t	i;

	i = 0;
	while (haystack[i] && needle[i] && i < hay_len)
	{
		if (haystack[i] != needle[i])
			return (-1);
		i++;
	}
	if (i == len)
		return (1);
	else
		return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;
	int		res;

	i = 0;
	count = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (len <= 0)
		return (0);
	while (needle[count])
		count++;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			res = find(&haystack[i], needle, count, len - i);
			if (res == 1)
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
