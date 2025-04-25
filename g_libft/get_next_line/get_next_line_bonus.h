/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:20:51 by aoger             #+#    #+#             */
/*   Updated: 2025/04/07 19:01:42 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../ft_std/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif