/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:40:40 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/07 14:41:24 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned long long a, int *res)
{
	if (a / 16)
	{
		print_hex(a / 16, res);
		print_hex(a % 16, res);
	}
	else
		*res += write(1, &"0123456789abcdef"[a % 16], 1);
}

int	print_ptr(unsigned long long a)
{
	int	res;

	res = write(1, "0x", 2);
	print_hex(a, &res);
	return (res);
}
