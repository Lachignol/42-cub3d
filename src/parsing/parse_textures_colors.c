/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:07:04 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:07:30 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_assign_texture(char **line, char **texture)
{
	int	end;

	if (*texture)
	{
		ft_print_error("Doublon for texture.");
		return (EXIT_FAILURE);
	}
	*line += 2;
	while (**line && ft_isspace(**line))
		(*line)++;
	end = 0;
	while ((*line)[end] && !ft_isspace((*line)[end]))
		end++;
	if (end == 0)
	{
		ft_print_error("Nothing to assign to a texture.");
		return (EXIT_FAILURE);
	}
	*texture = malloc(sizeof(char) * (end + 1));
	if (!*texture)
		return (perror("Memory allocation failed for texture"), EXIT_FAILURE);
	ft_strlcpy(*texture, *line, end + 1);
	*line += end;
	return (EXIT_SUCCESS);
}

static int	ft_assign_element(char **line, t_config *config)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (ft_strncmp(*line, "NO", 2) == 0)
		ret = ft_assign_texture(line, &config->north_texture);
	else if (ft_strncmp(*line, "SO", 2) == 0)
		ret = ft_assign_texture(line, &config->south_texture);
	else if (ft_strncmp(*line, "WE", 2) == 0)
		ret = ft_assign_texture(line, &config->west_texture);
	else if (ft_strncmp(*line, "EA", 2) == 0)
		ret = ft_assign_texture(line, &config->east_texture);
	else if (ft_strncmp(*line, "F", 1) == 0)
		ret = ft_parse_color(line, &config->floor_color);
	else if (ft_strncmp(*line, "C", 1) == 0)
		ret = ft_parse_color(line, &config->ceiling_color);
	if (ret != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_parse_elements(char *line, t_config *config)
{
	while (*line)
	{
		while (*line && ft_isspace(*line))
				line++;
		if (!*line)
			return (EXIT_SUCCESS);
		if (*line && (ft_is_texture_name(line) || ft_is_color_name(line)))
		{
			if (ft_assign_element(&line, config) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
		}
		else
		{
			ft_print_error("Wrong name for texture or color.");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

char	*ft_parse_textures_and_colors(int fd, t_cub3d *cub3d, int *gnl_pos)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line && ft_is_texture_or_color_empty(cub3d->config))
	{
		(*gnl_pos)++;
		i = 0;
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (ft_parse_elements(&line[i], &cub3d->config) != EXIT_SUCCESS)
			ft_exit_gnl_cub3d(line, fd, cub3d);
		free(line);
		line = get_next_line(fd);
	}
	if (ft_is_texture_or_color_empty(cub3d->config))
	{
		ft_print_error("Missing texture or color assignation");
		ft_exit_gnl_cub3d(line, fd, cub3d);
	}
	return (line);
}
