/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_textures_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:07:48 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:07:51 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_color_name(char *line)
{
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_is_texture_name(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 || \
		ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_is_texture_or_color_empty(t_config config)
{
	if (!config.north_texture || !config.south_texture || \
		!config.west_texture || !config.east_texture || \
		config.floor_color == -1 || config.ceiling_color == -1)
	{
		return (1);
	}
	return (0);
}
