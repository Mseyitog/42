/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:03:15 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/11 17:03:17 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	print_unsigned_int(unsigned int num)
{
	int	res;

	res = find_len(num);
	if (num / 10)
	{
		print_unsigned_int(num / 10);
		print_unsigned_int(num % 10);
	}
	else
		write(1, &"0123456789"[num % 10], 1);
	return (res);
}
