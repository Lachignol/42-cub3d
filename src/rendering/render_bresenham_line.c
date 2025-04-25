/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bresenham_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:01:56 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:01:57 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_error(int *err, int *dist_xy)
{
	if (dist_xy[0] > dist_xy[1])
		*err = dist_xy[0] / 2;
	else
		*err = -dist_xy[1] / 2;
}

static void	ft_setting_direction(int *is_x_dir_right, int *is_y_dir_up, \
int *start_xy, int *end_xy)
{
	if (start_xy[0] < end_xy[0])
		*is_x_dir_right = 1;
	else
		*is_x_dir_right = -1;
	if (start_xy[1] < end_xy[1])
		*is_y_dir_up = 1;
	else
		*is_y_dir_up = -1;
}

static void	ft_calculate_xy_distances(int *dist_xy, int *start_xy, \
int end_xy[2])
{
	dist_xy[0] = abs(end_xy[0] - start_xy[0]);
	dist_xy[1] = abs(end_xy[1] - start_xy[1]);
}

void	ft_draw_line(t_img *img, int start_xy[2], int end_xy[2], int color)
{
	int	dist_xy[2];
	int	is_x_dir_right;
	int	is_y_dir_up;
	int	err[2];

	ft_calculate_xy_distances(dist_xy, start_xy, end_xy);
	ft_setting_direction(&is_x_dir_right, &is_y_dir_up, start_xy, end_xy);
	ft_init_error(&err[0], dist_xy);
	while (1)
	{
		my_mlx_pixel_put(img, start_xy[0], start_xy[1], color);
		if (start_xy[0] == end_xy[0] && start_xy[1] == end_xy[1])
			break ;
		err[1] = err[0];
		if (err[1] > -dist_xy[0])
		{
			err[0] -= dist_xy[1];
			start_xy[0] += is_x_dir_right;
		}
		if (err[1] < dist_xy[1])
		{
			err[0] += dist_xy[0];
			start_xy[1] += is_y_dir_up;
		}
	}
}
