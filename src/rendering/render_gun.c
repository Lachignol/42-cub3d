/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:09 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:10 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calculate_offset(t_cub3d *cub3d, int *offset_xy)
{
	offset_xy[0] = 0;
	offset_xy[1] = 0;
	if (cub3d->gun_close)
		offset_xy[0] = cub3d->current_gun->width / NBR_OF_GUN_SPRITES;
	if (cub3d->gun_anim.is_animating)
		offset_xy[0] = cub3d->current_gun->width / NBR_OF_GUN_SPRITES \
			* (cub3d->gun_anim.frame + 1);
}

static void	ft_scale_pixel(t_img *img, int *scaled_render_xy, \
unsigned int color, double scale)
{
	int	x;
	int	y;

	y = 0;
	while (y < scale)
	{
		x = 0;
		while (x < scale)
		{
			my_mlx_pixel_put(img, scaled_render_xy[0] + x, \
				scaled_render_xy[1] + y, color);
			x++;
		}
		y++;
	}
}

static void	ft_draw_pixel_gun(t_cub3d *cub3d, int *scaled_render_xy, \
double scale, unsigned int color)
{
	if (scaled_render_xy[0] < cub3d->projection.width \
	&& scaled_render_xy[1] < cub3d->projection.height)
		ft_scale_pixel(&cub3d->render_img, scaled_render_xy, \
			color, scale);
}

static void	ft_draw_gun(t_cub3d *cub3d, int render_x, int render_y, \
double scale)
{
	int				x;
	int				y;
	unsigned int	color;
	int				scaled_render_xy[2];
	int				offset_xy[2];

	ft_calculate_offset(cub3d, offset_xy);
	y = 0;
	while (y < cub3d->current_gun->height)
	{
		x = 0;
		while (x < cub3d->current_gun->width / NBR_OF_GUN_SPRITES)
		{
			color = ft_get_pixel_color(cub3d->current_gun->addr, \
				cub3d->current_gun->width, x + offset_xy[0], y + offset_xy[1]);
			if (!ft_is_color_to_exclude(color))
			{
				scaled_render_xy[0] = render_x + x * scale;
				scaled_render_xy[1] = render_y + y * scale;
				ft_draw_pixel_gun(cub3d, scaled_render_xy, scale, color);
			}
			x++;
		}
		y++;
	}
}

void	ft_render_gun(t_cub3d *cub3d)
{
	int		gun_width;
	int		gun_height;
	int		render_x;
	int		render_y;
	double	scale;

	gun_width = cub3d->current_gun->width / NBR_OF_GUN_SPRITES;
	gun_height = cub3d->current_gun->height;
	scale = (double)cub3d->projection.width * GUN_SIZE_TO_SCREEN \
		/ (double)gun_width;
	render_x = (cub3d->projection.center_x - gun_width / 2 * scale) \
		+ (gun_width * GUN_X_OFFSET_TO_GUN_WIDTH * scale);
	render_y = cub3d->projection.height - gun_height * scale;
	ft_draw_gun(cub3d, render_x, render_y, scale);
}
