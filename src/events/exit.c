/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:18 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:19 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clean_config(t_config *config)
{
	if (config->map)
		ft_free_double_array(config->map);
	if (config->north_texture)
		free(config->north_texture);
	if (config->south_texture)
		free(config->south_texture);
	if (config->west_texture)
		free(config->west_texture);
	if (config->east_texture)
		free(config->east_texture);
	ft_bzero(config, sizeof(t_config));
}

void	ft_clean_cub3d(t_cub3d *cub3d)
{
	ft_clean_config(&cub3d->config);
}

void	ft_clean_all(t_cub3d *cub3d)
{
	ft_clean_cub3d(cub3d);
	ft_clean_mlx(cub3d, &cub3d->mlx);
	if (cub3d->rays)
		free(cub3d->rays);
}
