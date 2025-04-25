/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:12 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:13 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clean_game_images(t_cub3d *cub3d)
{
	if (cub3d->minimap.img.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->minimap.img.img_ptr);
	if (cub3d->render_img.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->render_img.img_ptr);
}

static void	ft_clean_images(t_cub3d *cub3d)
{
	if (cub3d->east_img.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->east_img.img_ptr);
	if (cub3d->south_img.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->south_img.img_ptr);
	if (cub3d->west_img.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->west_img.img_ptr);
	if (cub3d->north_img.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->north_img.img_ptr);
	if (cub3d->gun_blue.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->gun_blue.img_ptr);
	if (cub3d->gun_green.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->gun_green.img_ptr);
	if (cub3d->gun_purple.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->gun_purple.img_ptr);
	if (cub3d->gun_yellow.img_ptr)
		mlx_destroy_image(cub3d->mlx.mlx_ptr, cub3d->gun_yellow.img_ptr);
}

#ifdef __linux__

void	ft_clean_mlx(t_cub3d *cub3d, t_mlx *mlx)
{
	ft_clean_game_images(cub3d);
	ft_clean_images(cub3d);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}
#else

void	ft_clean_mlx(t_cub3d *cub3d, t_mlx *mlx)
{
	ft_clean_game_images(cub3d);
	ft_clean_wall_images(cub3d);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}
#endif
