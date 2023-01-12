/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseyitog <mseyitog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:01:48 by mseyitog          #+#    #+#             */
/*   Updated: 2022/10/15 14:04:50 by mseyitog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *str, int c);
char	*clear_save(char *save);
char	*read_file(int fd, char *save);
char	*get_line(char *save);

#endif