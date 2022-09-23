/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:24:51 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/07 14:29:39 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		print_char('-');
		n *= -1;
	}
	if (n / 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		print_char(n + 48);
}

int	print_int(int a)
{
	int	len;

	len = 0;
	ft_putnbr(a);
	if (a == 0)
		len++;
	if (a < 0)
		len++;
	while (a)
	{
		len++;
		a /= 10;
	}
	return (len);
}
