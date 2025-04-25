/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:08:36 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calculate_minimap_render_pos(t_cub3d *cub3d)
{
	cub3d->minimap.render_x = MINIMAP_MARGIN;
	cub3d->minimap.render_y = cub3d->projection.height \
		- cub3d->minimap.img.height - MINIMAP_MARGIN;
}

static void	ft_calculate_minimap_player(t_minimap *minimap)
{
	minimap->mmplayer.radius = minimap->block_size * \
							PLAYER_CIRCLE_DIAM_TO_BLOCK_SIZE / 2;
}

static void	ft_calculate_minimap_block_size(t_minimap *minimap)
{
	minimap->block_size = minimap->img.height / MINIMAP_BLOCKS_IN_HEIGHT;
	minimap->scaling = (double)minimap->block_size / BLOCK_SIZE;
}

static void	ft_calculate_minimap_size(t_mlx *mlx, t_minimap *minimap)
{
	minimap->img.width = MINIMAP_WIDTH;
	if (minimap->img.width > mlx->win_width * MINIMAP_MAX_WIDTH_TO_WIN)
		minimap->img.width = mlx->win_width * MINIMAP_MAX_WIDTH_TO_WIN;
	minimap->img.height = minimap->img.width;
	if (minimap->img.height > mlx->win_height * MINIMAP_MAX_HEIGHT_TO_WIN)
	{
		minimap->img.height = mlx->win_height * MINIMAP_MAX_HEIGHT_TO_WIN;
		minimap->img.width = minimap->img.height;
	}
	minimap->radius = minimap->img.width / 2;
	minimap->center_x = minimap->img.width / 2;
	minimap->center_y = minimap->img.height / 2;
}

void	ft_init_minimap(t_cub3d *cub3d, t_minimap *minimap, t_mlx *mlx)
{
	ft_calculate_minimap_size(mlx, minimap);
	ft_calculate_minimap_block_size(minimap);
	ft_calculate_minimap_player(minimap);
	ft_calculate_minimap_render_pos(cub3d);
	minimap->img.img_ptr = mlx_new_image(mlx->mlx_ptr, minimap->img.width, \
		minimap->img.height);
	minimap->img.addr = mlx_get_data_addr(minimap->img.img_ptr, \
							&minimap->img.bpp, &minimap->img.line_length, \
							&minimap->img.endian);
}
