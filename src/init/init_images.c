/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:28 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:08:30 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_img_data(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length, \
		&img->endian);
}

static void	ft_get_images_data(t_cub3d *cub3d)
{
	ft_get_img_data(&cub3d->east_img);
	ft_get_img_data(&cub3d->south_img);
	ft_get_img_data(&cub3d->west_img);
	ft_get_img_data(&cub3d->north_img);
	ft_get_img_data(&cub3d->gun_blue);
	ft_get_img_data(&cub3d->gun_green);
	ft_get_img_data(&cub3d->gun_purple);
	ft_get_img_data(&cub3d->gun_yellow);
}

static void	ft_load_mlx_img(t_cub3d *cub3d, t_img *img, \
void *mlx_ptr, char *filename)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, \
		&img->width, &img->height);
	if (!img->img_ptr)
	{
		ft_print_error("Failed to load XPM texture file");
		ft_clean_all(cub3d);
		exit(EXIT_FAILURE);
	}
}

static void	ft_load_assets_images(t_cub3d *cub3d, t_mlx *mlx, t_config *config)
{
	ft_load_mlx_img(cub3d, &cub3d->east_img, mlx->mlx_ptr, \
		config->east_texture);
	ft_load_mlx_img(cub3d, &cub3d->south_img, mlx->mlx_ptr, \
		config->south_texture);
	ft_load_mlx_img(cub3d, &cub3d->west_img, mlx->mlx_ptr, \
		config->west_texture);
	ft_load_mlx_img(cub3d, &cub3d->north_img, mlx->mlx_ptr, \
		config->north_texture);
	ft_load_mlx_img(cub3d, &cub3d->gun_blue, mlx->mlx_ptr, \
		"assets/gun_blue.xpm");
	ft_load_mlx_img(cub3d, &cub3d->gun_green, mlx->mlx_ptr, \
		"assets/gun_green.xpm");
	ft_load_mlx_img(cub3d, &cub3d->gun_purple, mlx->mlx_ptr, \
		"assets/gun_purple.xpm");
	ft_load_mlx_img(cub3d, &cub3d->gun_yellow, mlx->mlx_ptr, \
		"assets/gun_yellow.xpm");
}

void	ft_load_images(t_cub3d *cub3d)
{
	ft_load_assets_images(cub3d, &cub3d->mlx, &cub3d->config);
	ft_get_images_data(cub3d);
	cub3d->east_dst = &cub3d->east_img;
	cub3d->south_dst = &cub3d->south_img;
	cub3d->west_dst = &cub3d->west_img;
	cub3d->north_dst = &cub3d->north_img;
	cub3d->paintball_dst = &cub3d->north_img;
	cub3d->color_changed = 0;
	cub3d->current_gun = &cub3d->gun_blue;
}
