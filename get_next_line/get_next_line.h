/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:01:48 by mseyitog          #+#    #+#             */
/*   Updated: 2022/10/03 17:57:27 by mseyitog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFFER_SIZE 1
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*one_more(char *str, int *size);
char	*import(char *src, char *dest, int *size);
int		is_nl(char	*str);
int		red_lenght(char	*red, char	del);
void	clear_red(char **red, int len);
char	*get_line(char **red);
char	*get_char(int fd);

#endif