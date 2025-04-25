/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_rays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:13 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:14 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_find_end_xy_in_circle(t_minimap *minimap, int *start_xy, \
int *end_xy)
{
	double	dist_x;
	double	dist_y;
	double	dist;
	double	scale_factor;

	dist_x = end_xy[0] - start_xy[0];
	dist_y = end_xy[1] - start_xy[1];
	dist = ft_find_distance(start_xy[0], start_xy[1], end_xy[0], end_xy[1]);
	scale_factor = (minimap->radius - 0.001) / dist;
	end_xy[0] = start_xy[0] + (int)(dist_x * scale_factor);
	end_xy[1] = start_xy[1] + (int)(dist_y * scale_factor);
}

static void	ft_offset_mmray_distances(t_ray ray, int *end_xy)
{
	if (ray.is_hit_horizontal && ft_is_facing_up(ray.angle))
		end_xy[1] += 1;
	if (!ray.is_hit_horizontal && !ft_is_facing_right(ray.angle))
		end_xy[0] += 1;
}

static void	ft_draw_minimap_ray(t_minimap *minimap, t_ray ray, t_player player)
{
	int		start_xy[2];
	int		end_xy[2];
	double	dist_x;
	double	dist_y;

	dist_x = ray.hit_x - player.x;
	dist_y = ray.hit_y - player.y;
	start_xy[0] = minimap->center_x;
	start_xy[1] = minimap->center_y;
	end_xy[0] = start_xy[0] + dist_x * minimap->scaling;
	end_xy[1] = start_xy[1] + dist_y * minimap->scaling;
	ft_offset_mmray_distances(ray, end_xy);
	if (!ft_is_pixel_in_circle(start_xy[0], start_xy[1], end_xy[0], end_xy[1]))
		ft_find_end_xy_in_circle(minimap, start_xy, end_xy);
	ft_draw_line(&minimap->img, start_xy, end_xy, 0x0046D5FF);
}

void	ft_render_minimap_rays(t_ray *rays, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->projection.width)
	{
		if (i % 10 == 0 || i == cub3d->projection.width / 2)
		{
			ft_draw_minimap_ray(&cub3d->minimap, rays[i], cub3d->player);
		}
		i++;
	}
}
