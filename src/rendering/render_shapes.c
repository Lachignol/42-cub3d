/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:45 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:46 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_circle(t_img *img, int coord_xy[2], int radius, int color)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	y = coord_xy[1] - radius;
	while (y <= coord_xy[1] + radius)
	{
		x = coord_xy[0] - radius;
		while (x <= coord_xy[0] + radius)
		{
			dx = x - coord_xy[0];
			dy = y - coord_xy[1];
			if (dx * dx + dy * dy <= radius * radius)
			{
				if (x >= 0 && y >= 0)
					my_mlx_pixel_put(img, x, y, color);
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_rectangle(t_img *img, int coord_xy[2], int size_wh[2], \
int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_wh[1])
	{
		j = 0;
		while (j < size_wh[0])
		{
			my_mlx_pixel_put(img, coord_xy[0] + j, coord_xy[1] + i, color);
			j++;
		}
		i++;
	}
}
