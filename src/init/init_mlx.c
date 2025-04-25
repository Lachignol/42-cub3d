/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:41 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:08:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_setup_mlx_interactions(t_cub3d *cub3d, t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, ON_DESTROY, 1L << 0, ft_close_game, cub3d);
	mlx_hook(mlx->win_ptr, ON_KEYDOWN, 1L << 0, ft_handle_keypress, cub3d);
	mlx_hook(mlx->win_ptr, ON_KEYUP, 1L << 1, ft_handle_keyrelease, cub3d);
	mlx_hook(mlx->win_ptr, ON_MOUSEMOVE, 1L << 6, ft_handle_mouse_move, cub3d);
	mlx_hook(mlx->win_ptr, ON_MOUSEDOWN, 1L << 2, ft_handle_mouse_down, cub3d);
	mlx_loop_hook(mlx->mlx_ptr, ft_loop, cub3d);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	ft_calculate_win_size(t_cub3d *cub3d, t_mlx *mlx)
{
	if (mlx_get_screen_size(mlx->mlx_ptr, &mlx->win_width, \
	&mlx->win_height) == -1)
	{
		ft_clean_all(cub3d);
		exit(EXIT_FAILURE);
	}
	mlx->win_width *= WIN_WIDTH_TO_SCREEN;
	mlx->win_height *= WIN_HEIGHT_TO_SCREEN;
}

void	ft_init_mlx(t_cub3d *cub3d, t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	ft_calculate_win_size(cub3d, mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width, \
						mlx->win_height, "cub3d");
	ft_setup_mlx_interactions(cub3d, &cub3d->mlx);
	ft_load_images(cub3d);
}
//mlx_mouse_hide(mlx->mlx_ptr, mlx->win_ptr);
