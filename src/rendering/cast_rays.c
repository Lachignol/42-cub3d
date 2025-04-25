/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:01:27 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:01:30 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_correct_fisheye(t_cub3d *cub3d, t_ray *ray)
{
	ray->perp_dist = ray->dist * cos(ray->angle - cub3d->player.angle_rad);
}

static double	ft_calculate_start_angle(t_player player)
{
	double	start_angle;

	start_angle = player.angle_rad - (player.fov_rad / 2);
	return (start_angle);
}

void	ft_cast_rays(t_ray *rays, t_cub3d *cub3d)
{
	double	start_angle;
	double	current_angle;
	int		i;

	start_angle = ft_calculate_start_angle(cub3d->player);
	i = 0;
	while (i < cub3d->projection.width)
	{
		current_angle = start_angle + (i * cub3d->projection.ray_angle_inc);
		ft_normalize_rad_angle(&current_angle);
		rays[i].angle = current_angle;
		ft_find_closest_wall(cub3d, &rays[i]);
		ft_correct_fisheye(cub3d, &rays[i]);
		i++;
	}
}
