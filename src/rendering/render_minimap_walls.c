/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:17 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:02:18 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_expected_pixel(t_minimap *minimap, t_config *config, \
int minimap_j, int minimap_i)
{
	int	map_i;
	int	map_j;

	map_i = (minimap->mmplayer.printstart_y + minimap_i) / minimap->block_size;
	map_j = (minimap->mmplayer.printstart_x + minimap_j) / minimap->block_size;
	if (config->map[map_i][map_j] == '1')
		my_mlx_pixel_put(&minimap->img, minimap_j, minimap_i, 0x00020A12);
	else if (ft_is_floor_or_player(config->map[map_i][map_j]))
		my_mlx_pixel_put(&minimap->img, minimap_j, minimap_i, 0x00757B81);
	else
		my_mlx_pixel_put(&minimap->img, minimap_j, minimap_i, 0x99000000);
}

static int	ft_is_pixel_in_map(t_minimap *minimap, t_config *config, \
int minimap_i, int minimap_j)
{
	int	map_i;
	int	map_j;

	if (minimap->mmplayer.printstart_x + minimap_j < 0 \
	|| minimap->mmplayer.printstart_y + minimap_i < 0)
		return (0);
	map_i = (minimap->mmplayer.printstart_y + minimap_i) / minimap->block_size;
	map_j = (minimap->mmplayer.printstart_x + minimap_j) / minimap->block_size;
	if (map_i >= 0 && map_i < (int)config->map_height \
	&& map_j >= 0 && map_j < (int)config->map_width)
		return (1);
	return (0);
}

void	ft_draw_minimap(t_minimap *minimap, t_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->img.height)
	{
		j = 0;
		while (j < minimap->img.width)
		{
			if (ft_is_pixel_in_circle(minimap->center_x, minimap->center_y, \
			j, i) && ft_is_pixel_in_map(minimap, config, i, j))
				ft_draw_expected_pixel(minimap, config, j, i);
			else
				my_mlx_pixel_put(&minimap->img, j, i, 0x99000000);
			j++;
		}
		i++;
	}
}
