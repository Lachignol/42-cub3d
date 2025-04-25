/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:16 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:08:18 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_config(t_config *config, const char *map_file_path)
{
	config->map_file_path = map_file_path;
	config->floor_color = -1;
	config->ceiling_color = -1;
}
