/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:13 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:03:14 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_find_distance(int x0, int y0, int x1, int y1)
{
	double	dist_x;
	double	dist_y;
	double	dist;

	dist_x = x1 - x0;
	dist_y = y1 - y0;
	dist = sqrt(dist_x * dist_x + dist_y * dist_y);
	return (dist);
}
