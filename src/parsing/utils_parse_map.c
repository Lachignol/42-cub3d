/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:07:42 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:07:44 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_trim_backline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	ft_realign_gnl(char **line, int fd, int gnl_pos)
{
	*line = get_next_line(fd);
	while (*line && gnl_pos)
	{
		free(*line);
		*line = get_next_line(fd);
		gnl_pos--;
	}
}

int	ft_init_map(t_config *config)
{
	int	i;

	config->map = malloc(sizeof(char *) * (config->map_height + 1));
	if (!config->map)
	{
		ft_print_system_error("Memory allocation failed for map");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < config->map_height)
	{
		config->map[i] = malloc(sizeof(char) * (config->map_width + 1));
		if (!config->map[i])
		{
			ft_print_system_error("Memory allocation failed for map");
			ft_free_double_array(config->map);
			return (EXIT_FAILURE);
		}
		ft_bzero(config->map[i], sizeof(char) * (config->map_width + 1));
		i++;
	}
	config->map[i] = NULL;
	return (EXIT_SUCCESS);
}

int	ft_isonlymapchar(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line) && *line != '1' && *line != '0' && \
			*line != 'N' && *line != 'S' && *line != 'W' && *line != 'E')
		{
			return (0);
		}
		line++;
	}
	return (1);
}

int	ft_isonlyspaces(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
