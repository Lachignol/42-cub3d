/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:23 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:03:24 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_pixel_in_circle(int center_x, int center_y, int x, int y)
{
	int	dist_cent_x;
	int	dist_cent_y;
	int	radius_squared;
	int	dist_squared;

	dist_cent_x = x - center_x;
	dist_cent_y = y - center_y;
	radius_squared = center_x * center_x;
	dist_squared = dist_cent_x * dist_cent_x + dist_cent_y * dist_cent_y;
	if (dist_squared < radius_squared)
		return (1);
	return (0);
}
