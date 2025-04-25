/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:00 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:01 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_floor(t_cub3d *cub3d, t_projection projection, int x)
{
	int	end_y;
	int	i;

	end_y = projection.height;
	i = projection.height / 2;
	while (i < end_y)
	{
		my_mlx_pixel_put(&cub3d->render_img, x, i, cub3d->config.floor_color);
		i++;
	}
}

static void	ft_draw_ceiling(t_cub3d *cub3d, t_projection projection, int x)
{
	int	end_y;
	int	i;

	end_y = projection.height / 2;
	i = 0;
	while (i < end_y)
	{
		my_mlx_pixel_put(&cub3d->render_img, x, i, cub3d->config.ceiling_color);
		i++;
	}
}

void	ft_render_game_assets(t_cub3d *cub3d, t_ray *rays)
{
	int	i;

	i = 0;
	while (i < cub3d->projection.width)
	{
		ft_draw_ceiling(cub3d, cub3d->projection, i);
		ft_draw_floor(cub3d, cub3d->projection, i);
		ft_draw_wall_column(cub3d, &rays[i], i);
		i++;
	}
}
