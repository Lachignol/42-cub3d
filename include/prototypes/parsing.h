/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:11:03 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:11:04 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// parser.c
void	ft_parse_map_file(t_cub3d *cub3);

// check_file.c
void	ft_check_file_and_extension(const char *file_path, \
const char *extension);

// parse_texture_colors.c
char	*ft_parse_textures_and_colors(int fd, t_cub3d *cub3d, int *gnl_pos);

// parse.color.c
int		ft_parse_color(char **line, int *color);

// parse_map.c
void	ft_parse_map(int fd, t_cub3d *cub3d, int *gnl_pos, char **line);

// check_map.c
int		ft_check_walls(t_config config, int i, int j);
int		ft_check_floor_not_to_void(t_config config, int i, int j);
void	ft_check_player_placed(t_cub3d *cub3d, int i, int j, \
		int *player);
int		ft_is_floor_or_player(int c);
int		ft_isplayerchar(int c);

// utils_parse_texture_colors.c
int		ft_is_texture_or_color_empty(t_config config);
int		ft_is_texture_name(char *line);
int		ft_is_color_name(char *line);
void	ft_clean_gnl(char *line, int fd);
void	ft_exit_gnl_cub3d(char *line, int fd, t_cub3d *cub3d);

// utils_parse_map.c
int		ft_isonlymapchar(char *line);
int		ft_isonlyspaces(char *str);
int		ft_init_map(t_config *config);
void	ft_realign_gnl(char **line, int fd, int gnl_pos);
void	ft_trim_backline(char *line);

#endif
