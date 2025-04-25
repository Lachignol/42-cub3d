/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:04 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:05 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_game(t_cub3d *cub3d)
{
	ft_cast_rays(cub3d->rays, cub3d);
	ft_render_game_assets(cub3d, cub3d->rays);
	ft_render_gun(cub3d);
	ft_render_minimap(cub3d, cub3d->rays);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, \
		cub3d->render_img.img_ptr, 0, 0);
}
