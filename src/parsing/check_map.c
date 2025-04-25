/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:06:31 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:06:36 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isplayerchar(int c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

int	ft_is_floor_or_player(int c)
{
	return (c == '0' || ft_isplayerchar(c));
}

void	ft_check_player_placed(t_cub3d *cub3d, int i, int j, int *player)
{
	if (ft_isplayerchar(cub3d->config.map[i][j]))
	{
		*player += 1;
		if (*player == 1)
		{
			cub3d->player.x = j * BLOCK_SIZE + BLOCK_SIZE / 2;
			cub3d->player.y = i * BLOCK_SIZE + BLOCK_SIZE / 2;
			if (cub3d->config.map[i][j] == 'E')
				cub3d->player.init_angle_deg = 0;
			if (cub3d->config.map[i][j] == 'S')
				cub3d->player.init_angle_deg = 90;
			if (cub3d->config.map[i][j] == 'W')
				cub3d->player.init_angle_deg = 180;
			if (cub3d->config.map[i][j] == 'N')
				cub3d->player.init_angle_deg = 270;
		}
	}
}

int	ft_check_floor_not_to_void(t_config config, int i, int j)
{
	char	**map;
	int		height;
	int		width;

	map = config.map;
	height = config.map_height - 1;
	width = config.map_width - 1;
	if (ft_isspace(map[i][j]) || map[i][j] == '\0')
	{
		if ((i != 0 && ft_is_floor_or_player(map[i - 1][j])) || \
			(i != height && ft_is_floor_or_player(map[i + 1][j])) || \
			(j != 0 && ft_is_floor_or_player(map[i][j - 1])) || \
			(j != width && ft_is_floor_or_player(map[i][j + 1])))
		{
			ft_print_map_error("Player could fall into the void.");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_check_walls(t_config config, int i, int j)
{
	int	height;
	int	width;

	height = config.map_height - 1;
	width = config.map_width - 1;
	if (config.map[0][j] == '0' || ft_isplayerchar(config.map[0][j]))
		return (ft_print_map_error("Walls are not closed."), EXIT_FAILURE);
	else if (config.map[height][j] == '0' || \
	ft_isplayerchar(config.map[height][j]))
		return (ft_print_map_error("Walls are not closed."), EXIT_FAILURE);
	else if (config.map[i][0] == '0' || ft_isplayerchar(config.map[i][0]))
		return (ft_print_map_error("Walls are not closed."), EXIT_FAILURE);
	else if (config.map[i][width] == '0' || \
	ft_isplayerchar(config.map[i][width]))
		return (ft_print_map_error("Walls are not closed."), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
