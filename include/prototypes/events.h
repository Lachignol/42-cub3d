/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:10:54 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:10:55 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// utils_time.c
double	ft_get_delta_time(t_cub3d *cub3d);

// exit.c
void	ft_clean_cub3d(t_cub3d *cub3d);
void	ft_clean_all(t_cub3d *cub3d);

// exit_mlx.c
void	ft_clean_mlx(t_cub3d *cub3d, t_mlx *mlx);

// exit_parsing.c
void	ft_clean_gnl(char *line, int fd);
void	ft_exit_gnl_cub3d(char *line, int fd, t_cub3d *cub3d);
void	ft_exit_clean_cub3d(t_cub3d *cub3d);

// handle_keypress.c
int		ft_close_game(t_cub3d *cub3d);
int		ft_handle_keypress(int keycode, t_cub3d *cub3d);
int		ft_handle_keyrelease(int keycode, t_cub3d *cub3d);
int		ft_handle_mouse_move(int x, int y, t_cub3d *cub3d);
int		ft_handle_mouse_down(int button, int x, int y, t_cub3d *cub3d);

// loop.c
int		ft_loop(t_cub3d *cub3d);

// move_hero.c
void	ft_turn_hero(t_cub3d *cub3d);
int		ft_move_hero(t_cub3d *cub3d);

// paintball.c
t_img	*ft_fire_paintball(t_cub3d *cub3d);
void	ft_switch_paintball_color(t_cub3d *cub3d);
void	ft_paint_wall(t_cub3d *cub3d, t_img *img);
void	ft_switch_gun(t_cub3d *cub3d);
void	ft_watch_gun_distance(t_cub3d *cub3d);

// animation.c
void	ft_firearm(t_cub3d *cub3d);

#endif