/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:29 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:30 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turn_hero(t_cub3d *cub3d)
{
	double	new_angle;
	double	move;

	move = cub3d->player.rot_step_rad * cub3d->delta_time;
	new_angle = cub3d->player.angle_rad;
	if (cub3d->keys[KEY_LEFT])
		new_angle -= move;
	if (cub3d->keys[KEY_RIGHT])
		new_angle += move;
	ft_normalize_rad_angle(&new_angle);
	cub3d->player.angle_rad = new_angle;
}

static void	ft_calculate_directions(t_cub3d *cub3d, double *dir_x, \
double *dir_y)
{
	*dir_x = 0;
	*dir_y = 0;
	if (cub3d->keys[KEY_W])
	{
		*dir_x += cos(cub3d->player.angle_rad);
		*dir_y += sin(cub3d->player.angle_rad);
	}
	if (cub3d->keys[KEY_S])
	{
		*dir_x -= cos(cub3d->player.angle_rad);
		*dir_y -= sin(cub3d->player.angle_rad);
	}
	if (cub3d->keys[KEY_A])
	{
		*dir_x += cos(cub3d->player.angle_rad - M_PI_2);
		*dir_y += sin(cub3d->player.angle_rad - M_PI_2);
	}
	if (cub3d->keys[KEY_D])
	{
		*dir_x += cos(cub3d->player.angle_rad + M_PI_2);
		*dir_y += sin(cub3d->player.angle_rad + M_PI_2);
	}
}

static void	ft_calculate_moves(t_cub3d *cub3d, double *move_x, double *move_y)
{
	double	dir_x;
	double	dir_y;
	double	len;
	double	move;

	ft_calculate_directions(cub3d, &dir_x, &dir_y);
	len = sqrt(dir_x * dir_x + dir_y * dir_y);
	if (len > 0)
	{
		move = cub3d->player.move_step * cub3d->delta_time;
		*move_x = (dir_x / len) * move;
		*move_y = (dir_y / len) * move;
	}
	else
	{
		*move_x = 0;
		*move_y = 0;
	}
}

int	ft_move_hero(t_cub3d *cub3d)
{
	double	move_x;
	double	move_y;
	double	new_x;
	double	new_y;

	ft_calculate_moves(cub3d, &move_x, &move_y);
	if (move_x != 0 || move_y != 0)
	{
		new_x = cub3d->player.x + move_x;
		new_y = cub3d->player.y + move_y;
		if (!ft_is_wall_collision(&cub3d->config, new_x, new_y))
		{
			cub3d->player.x = new_x;
			cub3d->player.y = new_y;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
