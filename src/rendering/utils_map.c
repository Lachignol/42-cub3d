/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:17 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:03:18 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_out_of_map(t_config config, double x, double y)
{
	if (x < 0 || y < 0 || \
		x >= config.map_width * BLOCK_SIZE || \
		y >= config.map_height * BLOCK_SIZE)
	{
		return (1);
	}
	return (0);
}

int	ft_is_wall_collision(t_config *config, int x, int y)
{
	int	i;
	int	j;

	i = y / BLOCK_SIZE;
	j = x / BLOCK_SIZE;
	if (i < 0 || i >= config->map_height \
	|| j < 0 || j >= config->map_width)
		return (0);
	if (config->map[i][j] == '1')
		return (1);
	return (0);
}
