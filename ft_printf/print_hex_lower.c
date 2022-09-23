/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:37:32 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/16 21:37:36 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned int a, int *res)
{
	if (a / 16)
	{
		print_hex(a / 16, res);
		print_hex(a % 16, res);
	}
	else
		*res += write(1, &"0123456789abcdef"[a % 16], 1);
}

int	print_hex_lower(unsigned int a)
{
	int	res;

	res = 0;
	print_hex(a, &res);
	return (res);
}