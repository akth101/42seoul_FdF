/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:42:54 by seongjko          #+#    #+#             */
/*   Updated: 2023/05/12 19:42:56 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*line(char **rest, int fd);
char	*cut(char **rest, int new_iso_pos, int i);
char	*ft_strrest_gnl(char *buff, int new_iso_pos);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strndup_gnl(char *str, int len);
char	*ft_strjoin_gnl(char *dest, char *append);
size_t	ft_strlen_gnl(const char *str);

#endif