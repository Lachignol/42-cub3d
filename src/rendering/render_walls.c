/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:02 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:03:03 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*ft_get_target_texture(t_cub3d *cub3d, t_ray *ray)
{
	t_img	*img;

	img = NULL;
	if (ft_is_facing_right(ray->angle) && !ray->is_hit_horizontal)
		img = cub3d->east_dst;
	else if (!ft_is_facing_right(ray->angle) && !ray->is_hit_horizontal)
		img = cub3d->west_dst;
	else if (ft_is_facing_up(ray->angle) && ray->is_hit_horizontal)
		img = cub3d->north_dst;
	else if (!ft_is_facing_up(ray->angle) && ray->is_hit_horizontal)
		img = cub3d->south_dst;
	return (img);
}

static int	ft_get_end_y(int start_y, int wall_height, int win_height)
{
	int	end_y;

	end_y = start_y + wall_height;
	if (end_y > win_height)
		end_y = win_height;
	return (end_y);
}

static int	ft_get_start_y(t_projection projection, int wall_height)
{
	int	y_start_draw;

	y_start_draw = projection.center_y - (wall_height / 2);
	if (y_start_draw < 0)
		y_start_draw = 0;
	return (y_start_draw);
}

void	ft_draw_wall_column(t_cub3d *cub3d, t_ray *ray, int x)
{
	int				start_y;
	int				end_y;
	t_img			*img;
	int				y;
	unsigned int	color;

	ray->wall_height = BLOCK_SIZE / ray->perp_dist * cub3d->projection.distance;
	start_y = ft_get_start_y(cub3d->projection, ray->wall_height);
	end_y = ft_get_end_y(start_y, ray->wall_height, cub3d->projection.height);
	img = ft_get_target_texture(cub3d, ray);
	y = 0;
	while (y + start_y < end_y)
	{
		color = ft_get_texture_pixel_color(cub3d, img, ray, y);
		my_mlx_pixel_put(&cub3d->render_img, x, y + start_y, color);
		y++;
	}
}
