/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:14:56 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/17 02:14:59 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_int(int a);
int	print_char(int a);
int	print_str(char *str);
int	print_ptr(unsigned long long a);
int	print_unsigned_int(unsigned int num);
int	print_hex_lower(unsigned int a);
int	print_hex_upper(unsigned int a);
int	print_perc(int c);

#endif
