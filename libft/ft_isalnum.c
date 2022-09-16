/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:23:47 by mseyitog          #+#    #+#             */
/*   Updated: 2022/09/12 22:23:59 by mseyitog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((arg <= 'Z' && arg >= 'A') || (arg <= 'z' && arg >= 'a'))
		return (1);
	if (arg <= 57 && arg >= 48)
		return (1);
	else
		return (0);
}
