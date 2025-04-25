/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:06:49 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:06:51 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_map_size(char **line, int fd, t_config *config, \
t_cub3d *cub3d)
{
	int	temp_map_width;

	temp_map_width = 0;
	while (*line)
	{
		ft_trim_backline(*line);
		if (*line[0] == '\0' || ft_isonlyspaces(*line) || \
		!ft_isonlymapchar(*line))
			return (ft_print_error("Invalid char in map."), \
					ft_exit_gnl_cub3d(*line, fd, cub3d));
		temp_map_width = ft_strlen(*line);
		if (temp_map_width > config->map_width)
			config->map_width = temp_map_width;
		config->map_height++;
		free(*line);
		*line = get_next_line(fd);
	}
	close(fd);
	if (config->map_width < 3 || config->map_height < 3)
	{
		ft_print_error("Map minimum width & height: 3");
		ft_exit_clean_cub3d(cub3d);
	}
}

static void	ft_fill_map(t_config *config, int gnl_pos, t_cub3d *cub3d)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(config->map_file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_print_system_error("Cannot open file");
		ft_exit_clean_cub3d(cub3d);
	}
	ft_realign_gnl(&line, fd, gnl_pos);
	i = 0;
	while (line)
	{
		ft_trim_backline(line);
		ft_strlcpy(config->map[i], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

static int	ft_check_valid_map(t_config config, t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	player_flag;

	player_flag = 0;
	i = 0;
	while (i < config.map_height)
	{
		j = 0;
		while (j < config.map_width)
		{
			if (ft_check_walls(config, i, j) != EXIT_SUCCESS || \
			ft_check_floor_not_to_void(config, i, j) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			ft_check_player_placed(cub3d, i, j, &player_flag);
			j++;
		}
		i++;
	}
	if (player_flag != 1)
	{
		ft_print_map_error("Wrong number of players.");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_parse_map(int fd, t_cub3d *cub3d, int *gnl_pos, char **line)
{
	while (*line && ft_isonlyspaces(*line))
	{
		(*gnl_pos)++;
		free(*line);
		*line = get_next_line(fd);
	}
	ft_get_map_size(line, fd, &cub3d->config, cub3d);
	if (ft_init_map(&cub3d->config) != EXIT_SUCCESS)
		ft_exit_clean_cub3d(cub3d);
	ft_fill_map(&cub3d->config, *gnl_pos, cub3d);
	if (ft_check_valid_map(cub3d->config, cub3d) != EXIT_SUCCESS)
		ft_exit_clean_cub3d(cub3d);
}
