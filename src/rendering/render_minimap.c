/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:21 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:22 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_minimap_on_render_img(t_cub3d *cub3d)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < cub3d->minimap.img.height)
	{
		x = 0;
		while (x < cub3d->minimap.img.width)
		{
			color = ft_get_pixel_color(cub3d->minimap.img.addr, \
				cub3d->minimap.img.width, x, y);
			if (color != 0x99000000)
				my_mlx_pixel_put(&cub3d->render_img, \
					x + cub3d->minimap.render_x, \
					y + cub3d->minimap.render_y, color);
			x++;
		}
		y++;
	}
}

static void	ft_draw_player(t_minimap *minimap)
{
	int	coord_xy[2];

	coord_xy[0] = minimap->center_x;
	coord_xy[1] = minimap->center_y;
	ft_draw_circle(&minimap->img, coord_xy, minimap->mmplayer.radius, \
		0x00233CBA);
}

static void	ft_get_minimap_printstart_coord(t_minimap *minimap)
{
	minimap->mmplayer.printstart_x = minimap->mmplayer.x - minimap->radius;
	minimap->mmplayer.printstart_y = minimap->mmplayer.y - minimap->radius;
}

static void	ft_get_minimap_player_coord(t_minimap *minimap, t_player *player)
{
	minimap->mmplayer.x = (player->x * minimap->block_size) / BLOCK_SIZE;
	minimap->mmplayer.y = (player->y * minimap->block_size) / BLOCK_SIZE;
}

void	ft_render_minimap(t_cub3d *cub3d, t_ray *rays)
{
	ft_get_minimap_player_coord(&cub3d->minimap, &cub3d->player);
	ft_get_minimap_printstart_coord(&cub3d->minimap);
	ft_draw_minimap(&cub3d->minimap, &cub3d->config);
	ft_render_minimap_rays(rays, cub3d);
	ft_draw_player(&cub3d->minimap);
	ft_draw_minimap_on_render_img(cub3d);
}
