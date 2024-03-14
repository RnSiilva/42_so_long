/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:18:39 by resilva           #+#    #+#             */
/*   Updated: 2023/11/02 19:27:05 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_read_line(int fd, char *left_str);
char	*ft_strjoin(char *left_str, char *buff);

#endif