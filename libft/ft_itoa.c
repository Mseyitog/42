/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:26:26 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:26:38 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_len(int *len, int num)
{
	char	*res;

	while (num > 9)
	{
		(*len)++;
		num /= 10;
	}
	res = (char *)malloc(((*len) + 1) * sizeof(char));
	if (!res)
	{
		(*len) = 0;
		return (0);
	}
	res[*len] = 0;
	return (res);
}

static void	loop(int len, int n, int sign, char *res)
{
	while (len > 0)
	{
		if (len == 1 && sign == -1)
			res[0] = '-';
		else
			res[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	sign = 1;
	len = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		sign *= -1;
		len ++;
	}
	res = find_len(&len, n);
	loop(len, n, sign, res);
	return (res);
}
