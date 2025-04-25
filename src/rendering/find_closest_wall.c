/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:01:48 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:01:49 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_next_inter(double *x, double *y, \
double dist_x_next_inter, double dist_y_next_inter)
{
	*x += dist_x_next_inter;
	*y += dist_y_next_inter;
}

static void	ft_setting_ray(t_ray *ray, double dist, int is_hit_horizontal, \
double *hit_xy)
{
	ray->dist = dist;
	ray->is_hit_horizontal = is_hit_horizontal;
	ray->hit_x = hit_xy[0];
	ray->hit_y = hit_xy[1];
}

void	ft_find_closest_wall(t_cub3d *cub3d, t_ray *ray)
{
	double	h_dist;
	double	v_dist;
	double	h_hit_xy[2];
	double	v_hit_xy[2];

	ft_bzero(h_hit_xy, sizeof(h_hit_xy));
	ft_bzero(v_hit_xy, sizeof(v_hit_xy));
	h_dist = INFINITY;
	v_dist = INFINITY;
	if (!ft_is_ray_perfect_horizontal(ray->angle))
		h_dist = ft_find_closest_horizontal_wall(cub3d, ray, &cub3d->player, \
			h_hit_xy);
	if (!ft_is_ray_perfect_vertical(ray->angle))
		v_dist = ft_find_closest_vertical_wall(cub3d, ray, &cub3d->player, \
			v_hit_xy);
	if (h_dist < v_dist)
		ft_setting_ray(ray, h_dist, 1, h_hit_xy);
	else
		ft_setting_ray(ray, v_dist, 0, v_hit_xy);
}
