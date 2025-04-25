/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_horizontal_wall.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:01:35 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:01:37 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_ray_perfect_horizontal(double rad_angle)
{
	if (fabs(sin(rad_angle)) < 0.001)
		return (1);
	return (0);
}

static void	ft_find_distances_next_inter(t_ray *ray, double *dist_x_next_inter, \
double *dist_y_next_inter)
{
	if (ft_is_facing_up(ray->angle))
		*dist_y_next_inter = -BLOCK_SIZE;
	else
		*dist_y_next_inter = BLOCK_SIZE;
	*dist_x_next_inter = *dist_y_next_inter / tan(ray->angle);
}

static void	ft_find_first_inter(t_player *player, t_ray *ray, \
double *first_hit_x, double *first_hit_y)
{
	double	dist_y;

	if (ft_is_facing_up(ray->angle))
		*first_hit_y = floor(player->y / BLOCK_SIZE) * BLOCK_SIZE - 0.001;
	else
		*first_hit_y = floor(player->y / BLOCK_SIZE) * BLOCK_SIZE \
			+ BLOCK_SIZE;
	dist_y = *first_hit_y - player->y;
	*first_hit_x = player->x + dist_y / tan(ray->angle);
}

double	ft_find_closest_horizontal_wall(t_cub3d *cub3d, t_ray *ray, \
t_player *player, double *hit_xy)
{
	double	first_hit_x;
	double	first_hit_y;
	double	dist_x_next_inter;
	double	dist_y_next_inter;

	ft_find_first_inter(player, ray, &first_hit_x, &first_hit_y);
	if (ft_is_wall_collision(&cub3d->config, first_hit_x, first_hit_y))
	{
		hit_xy[0] = first_hit_x;
		hit_xy[1] = first_hit_y;
		return (ft_find_distance(player->x, player->y, \
			first_hit_x, first_hit_y));
	}
	ft_find_distances_next_inter(ray, &dist_x_next_inter, &dist_y_next_inter);
	while (!ft_is_wall_collision(&cub3d->config, first_hit_x, first_hit_y))
	{
		ft_find_next_inter(&first_hit_x, &first_hit_y, dist_x_next_inter, \
			dist_y_next_inter);
		if (ft_is_out_of_map(cub3d->config, first_hit_x, first_hit_y))
			return (INFINITY);
	}
	hit_xy[0] = first_hit_x;
	hit_xy[1] = first_hit_y;
	return (ft_find_distance(player->x, player->y, first_hit_x, first_hit_y));
}
