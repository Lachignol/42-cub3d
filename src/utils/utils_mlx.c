/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:09:23 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:09:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_get_pixel_color(char *addr, int width, int x, int y)
{
	int	color;

	color = ((unsigned int *)addr)[y * width + x];
	return (color);
}
