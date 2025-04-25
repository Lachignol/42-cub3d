/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paintball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:33 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:34 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_watch_gun_distance(t_cub3d *cub3d)
{
	t_ray	ray;

	ray.angle = cub3d->player.angle_rad;
	ft_find_closest_wall(cub3d, &ray);
	if (ray.dist < 500)
		cub3d->gun_close = 1;
	else
		cub3d->gun_close = 0;
}

void	ft_paint_wall(t_cub3d *cub3d, t_img *img)
{
	if (img == &cub3d->north_img)
		cub3d->north_dst = cub3d->paintball_dst;
	else if (img == &cub3d->east_img)
		cub3d->east_dst = cub3d->paintball_dst;
	else if (img == &cub3d->south_img)
		cub3d->south_dst = cub3d->paintball_dst;
	else if (img == &cub3d->west_img)
		cub3d->west_dst = cub3d->paintball_dst;
}

void	ft_switch_gun(t_cub3d *cub3d)
{
	if (cub3d->current_gun == &cub3d->gun_blue)
		cub3d->current_gun = &cub3d->gun_yellow;
	else if (cub3d->current_gun == &cub3d->gun_yellow)
		cub3d->current_gun = &cub3d->gun_green;
	else if (cub3d->current_gun == &cub3d->gun_green)
		cub3d->current_gun = &cub3d->gun_purple;
	else if (cub3d->current_gun == &cub3d->gun_purple)
		cub3d->current_gun = &cub3d->gun_blue;
}

void	ft_switch_paintball_color(t_cub3d *cub3d)
{
	if (cub3d->paintball_dst == &cub3d->north_img)
		cub3d->paintball_dst = &cub3d->east_img;
	else if (cub3d->paintball_dst == &cub3d->east_img)
		cub3d->paintball_dst = &cub3d->south_img;
	else if (cub3d->paintball_dst == &cub3d->south_img)
		cub3d->paintball_dst = &cub3d->west_img;
	else if (cub3d->paintball_dst == &cub3d->west_img)
		cub3d->paintball_dst = &cub3d->north_img;
}

t_img	*ft_fire_paintball(t_cub3d *cub3d)
{
	t_img	*img;
	t_ray	ray;

	img = NULL;
	ray.angle = cub3d->player.angle_rad;
	ft_find_closest_wall(cub3d, &ray);
	if (ray.dist < 500)
	{
		if (ft_is_facing_up(ray.angle) && ray.is_hit_horizontal)
			img = &cub3d->north_img;
		else if (!ft_is_facing_up(ray.angle) && ray.is_hit_horizontal)
			img = &cub3d->south_img;
		else if (ft_is_facing_right(ray.angle) && !ray.is_hit_horizontal)
			img = &cub3d->east_img;
		else if (!ft_is_facing_right(ray.angle) && !ray.is_hit_horizontal)
			img = &cub3d->west_img;
	}
	return (img);
}
