/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:06:42 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:06:44 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_valid_color(char *color, int *rgb_color)
{
	int	j;

	if (ft_strlen(color) == 0 || ft_strlen(color) > 3)
	{
		ft_print_error("Invalid numbers for color. Usage: '255,255,255'");
		return (EXIT_FAILURE);
	}
	j = 0;
	while (color[j])
	{
		if (!ft_isdigit(color[j]))
		{
			ft_print_error("Invalid numbers for color. Usage: '255,255,255'");
			return (EXIT_FAILURE);
		}
		j++;
	}
	*rgb_color = ft_atoi(color);
	if (*rgb_color < 0 || *rgb_color > 255)
	{
		ft_print_error("Invalid range for color. Usage: '255,255,255'");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_parse_split_colors(char **split_colors, int *color)
{
	int	i;
	int	rgb_colors[3];

	if (!split_colors[0] || !split_colors[1] || \
		!split_colors[2] || split_colors[3])
	{
		ft_print_error("Invalid sequence for color numbers. \
Usage: '255,255,255'");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (split_colors[i])
	{
		if (ft_check_valid_color(split_colors[i], &rgb_colors[i]) \
		!= EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	*color = (rgb_colors[0] << 16) | (rgb_colors[1] << 8) | rgb_colors[2];
	return (EXIT_SUCCESS);
}

static int	ft_find_color_line(char **line, int *end)
{
	(*line)++;
	while (**line && ft_isspace(**line))
		(*line)++;
	*end = 0;
	while ((*line)[*end] && !ft_isspace((*line)[*end]))
		(*end)++;
	if (*end == 0)
	{
		ft_print_error("Nothing to assign to a color.");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_parse_color(char **line, int *color)
{
	int		end;
	char	*str_color;
	char	**split_colors;

	if (*color != -1)
	{
		ft_print_error("Doublon for color.");
		return (EXIT_FAILURE);
	}
	if (ft_find_color_line(line, &end) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	str_color = malloc(sizeof(char) * (end + 1));
	if (!str_color)
		return (perror("Memory allocation failed for color"), EXIT_FAILURE);
	ft_strlcpy(str_color, *line, end + 1);
	split_colors = ft_split(str_color, ',');
	free(str_color);
	if (!split_colors)
		return (perror("Memory allocation failed: split_color"), EXIT_FAILURE);
	if (ft_parse_split_colors(split_colors, color) != EXIT_SUCCESS)
		return (ft_free_double_array(split_colors), EXIT_FAILURE);
	*line += end;
	return (ft_free_double_array(split_colors), EXIT_SUCCESS);
}
