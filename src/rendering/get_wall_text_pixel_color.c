/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_text_pixel_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:01:52 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:01:53 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_wall_img_y_to_print(t_cub3d *cub3d, t_img *img, \
t_ray *ray, int render_y)
{
	int	tex_y;
	int	wall_screen_offset;

	if (ray->wall_height <= cub3d->projection.height)
		tex_y = (int)(((double)render_y / ray->wall_height) * img->height);
	else
	{
		wall_screen_offset = (ray->wall_height - cub3d->projection.height) / 2;
		tex_y = (int)(((double)(render_y + wall_screen_offset) \
			/ ray->wall_height) * img->height);
	}
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= img->height)
		tex_y = img->height - 1;
	return (tex_y);
}

static int	ft_get_wall_img_x_to_print(t_img *img, t_ray *ray)
{
	int	x;

	x = 0;
	if (ray->is_hit_horizontal)
		x = (int)ray->hit_x % img->width;
	else if (!ray->is_hit_horizontal)
		x = (int)ray->hit_y % img->width;
	return (x);
}

unsigned int	ft_get_texture_pixel_color(t_cub3d *cub3d, t_img *img, \
t_ray *ray, int render_y)
{
	int				tex_x;
	int				tex_y;
	unsigned int	color;

	tex_x = ft_get_wall_img_x_to_print(img, ray);
	tex_y = ft_get_wall_img_y_to_print(cub3d, img, ray, render_y);
	color = ft_get_pixel_color(img->addr, img->width, tex_x, tex_y);
	return (color);
}
