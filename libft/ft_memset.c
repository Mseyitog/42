/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:36:34 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:36:45 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = x;
		i ++;
	}
	return (ptr);
}
