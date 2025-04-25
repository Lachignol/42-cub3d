/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:11:14 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:11:15 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// print_error.c
void			ft_print_system_error(char *message);
void			ft_print_error(char *message);
void			ft_print_map_error(char *message);

// ft_std.c
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(int c);

// array_utils.c
void			ft_free_double_array(char **array);
int				ft_malloc_double_array(char ***array, int width, int height);

// utils_mlx.c
unsigned int	ft_get_pixel_color(char *addr, int width, int x, int y);

#endif
