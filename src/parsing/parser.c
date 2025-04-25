/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:07:36 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:07:38 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_parse_file_content(t_cub3d *cub3d)
{
	int		fd;
	int		gnl_pos;
	char	*line;

	fd = open(cub3d->config.map_file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_print_system_error("Cannot open file");
		exit(EXIT_FAILURE);
	}
	gnl_pos = 0;
	line = ft_parse_textures_and_colors(fd, cub3d, &gnl_pos);
	ft_parse_map(fd, cub3d, &gnl_pos, &line);
	close(fd);
}

void	ft_parse_map_file(t_cub3d *cub3d)
{
	ft_check_file_and_extension(cub3d->config.map_file_path, ".cub");
	ft_parse_file_content(cub3d);
}
