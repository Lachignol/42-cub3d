/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:22 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:23 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_mouse_down(int button, int x, int y, t_cub3d *cub3d)
{
	t_img	*img;

	(void)x;
	(void)y;
	if (button == MOUSE_BTN_LEFT)
	{
		img = ft_fire_paintball(cub3d);
		if (img)
		{
			cub3d->gun_anim.is_animating = 1;
			ft_paint_wall(cub3d, img);
			cub3d->color_changed = 1;
		}
	}
	else if (button == MOUSE_BTN_RIGHT)
	{
		ft_switch_paintball_color(cub3d);
		ft_switch_gun(cub3d);
		cub3d->color_changed = 1;
	}
	return (EXIT_SUCCESS);
}

int	ft_handle_mouse_move(int x, int y, t_cub3d *cub3d)
{
	int		center_x;
	int		center_y;
	int		delta_x;
	double	new_angle;

	center_x = cub3d->projection.center_x;
	center_y = cub3d->projection.center_y;
	if (x == center_x && y == center_y)
		return (0);
	new_angle = cub3d->player.angle_rad;
	delta_x = x - center_x;
	if (delta_x > 0)
		new_angle += delta_x * MOUSE_SENSITIVITY * cub3d->delta_time;
	else if (delta_x < 0)
		new_angle -= -delta_x * MOUSE_SENSITIVITY * cub3d->delta_time;
	ft_normalize_rad_angle(&new_angle);
	if (new_angle != cub3d->player.angle_rad)
		cub3d->turn = 1;
	cub3d->player.angle_rad = new_angle;
	mlx_mouse_move(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, center_x, center_y);
	return (EXIT_SUCCESS);
}

int	ft_close_game(t_cub3d *cub3d)
{
	ft_clean_all(cub3d);
	exit(EXIT_SUCCESS);
}

int	ft_handle_keyrelease(int keycode, t_cub3d *cub3d)
{
	cub3d->keys[keycode] = 0;
	return (EXIT_SUCCESS);
}

int	ft_handle_keypress(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
		ft_close_game(cub3d);
	cub3d->keys[keycode] = 1;
	return (EXIT_SUCCESS);
}
