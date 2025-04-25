/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:10:59 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:11:00 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

// init_config.c
void	ft_init_config(t_config *config, const char *map_file_path);

// init_mlx.c
void	ft_init_mlx(t_cub3d *cub3d, t_mlx *mlx);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// init_game.c
void	ft_init_game(t_cub3d *cub3d);

// init_minimap.c
void	ft_init_minimap(t_cub3d *cub3d, t_minimap *minimap, t_mlx *mlx);

// init_images.c
void	ft_load_images(t_cub3d *cub3d);

// init_animations.c
void	ft_init_gun_animation(t_cub3d *cub3d);

#endif