/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:52:13 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/07 14:40:32 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	perc(va_list args, const char *str, int i, int *ret)
{
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		*ret += print_int(va_arg(args, int));
	else if (str[i + 1] == 'c')
		*ret += print_char(va_arg(args, int));
	else if (str[i + 1] == 's')
		*ret += print_str(va_arg(args, char *));
	else if (str[i + 1] == 'p')
		*ret += print_ptr(va_arg(args, unsigned long long));
	else if (str[i + 1] == 'u')
		*ret += print_unsigned_int(va_arg(args, unsigned int));
	else if (str[i + 1] == 'x')
		*ret += print_hex_lower(va_arg(args, unsigned int));
	else if (str[i + 1] == 'X')
		*ret += print_hex_upper(va_arg(args, unsigned int));
	else if (str[i + 1] == '%')
		*ret += print_perc('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			perc(args, str, i, &ret);
			i++;
		}
		else
			ret += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}