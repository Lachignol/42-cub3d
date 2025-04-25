/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:22 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:08:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_render_img(t_cub3d *cub3d, t_img *render_img)
{
	render_img->width = cub3d->projection.width;
	render_img->height = cub3d->projection.height;
	render_img->img_ptr = mlx_new_image(cub3d->mlx.mlx_ptr, \
		render_img->width, render_img->height);
	render_img->addr = mlx_get_data_addr(render_img->img_ptr, \
		&render_img->bpp, &render_img->line_length, &render_img->endian);
}

static void	ft_init_last_frame(struct timeval *last_frame)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	*last_frame = current_time;
}

static void	ft_init_projection(t_projection *projection, t_player player, \
t_mlx mlx)
{
	projection->width = mlx.win_width;
	projection->height = mlx.win_height;
	projection->center_x = projection->width / 2;
	projection->center_y = projection->height / 2;
	projection->distance = (projection->width / 2) \
							/ tan(player.fov_rad / 2);
	projection->ray_angle_inc = player.fov_rad / projection->width;
}

static void	ft_init_player(t_player *player)
{
	player->x += 0.001;
	player->y += 0.001;
	player->angle_rad = player->init_angle_deg * (M_PI / 180);
	player->dir_x = cos(player->angle_rad);
	player->dir_y = sin(player->angle_rad);
	player->fov_rad = FOV_DEG * (M_PI / 180);
	player->move_step = PLAYER_STEP_SIZE_TO_BLOCK_SIZE * BLOCK_SIZE;
	player->rot_step_rad = PLAYER_ROT_DEG * (M_PI / 180);
	player->height = BLOCK_SIZE / 2;
}

void	ft_init_game(t_cub3d *cub3d)
{
	ft_init_mlx(cub3d, &cub3d->mlx);
	ft_init_player(&cub3d->player);
	ft_init_projection(&cub3d->projection, cub3d->player, cub3d->mlx);
	ft_init_minimap(cub3d, &cub3d->minimap, &cub3d->mlx);
	ft_init_render_img(cub3d, &cub3d->render_img);
	cub3d->rays = malloc(cub3d->projection.width * sizeof(t_ray));
	if (!cub3d->rays)
	{
		ft_clean_all(cub3d);
		exit(EXIT_FAILURE);
	}
	ft_init_last_frame(&cub3d->last_frame);
	ft_init_gun_animation(cub3d);
	cub3d->gun_close = 0;
	cub3d->watch_gun_close = cub3d->gun_close;
}
