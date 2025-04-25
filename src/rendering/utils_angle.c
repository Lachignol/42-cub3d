/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:05 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:03:06 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_facing_right(double angle_rad)
{
	if (cos(angle_rad) > 0)
		return (1);
	return (0);
}

int	ft_is_facing_up(double rad_angle)
{
	if (sin(rad_angle) < 0)
		return (1);
	return (0);
}

void	ft_normalize_rad_angle(double *rad_angle)
{
	while (*rad_angle < 0)
		*rad_angle += 2 * M_PI;
	while (*rad_angle >= 2 * M_PI)
		*rad_angle -= 2 * M_PI;
}
