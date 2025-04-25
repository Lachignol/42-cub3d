/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:11:24 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:11:25 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_projection
{
	int		width;
	int		height;
	int		center_x;
	int		center_y;
	double	distance;
	double	ray_angle_inc;
}	t_projection;

typedef struct s_ray
{
	double	angle;
	double	dist;
	double	perp_dist;
	int		is_hit_horizontal;
	double	hit_x;
	double	hit_y;
	int		wall_height;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	init_angle_deg;
	double	angle_rad;
	double	dir_x;
	double	dir_y;
	double	fov_rad;
	double	move_step;
	double	rot_step_rad;
	double	height;
}	t_player;

typedef struct s_config
{
	const char	*map_file_path;
	char		**map;
	int			map_width;
	int			map_height;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
}	t_config;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mmplayer
{
	int	x;
	int	y;
	int	radius;
	int	printstart_x;
	int	printstart_y;
}	t_mmplayer;

typedef struct s_minimap
{
	int			center_x;
	int			center_y;
	int			radius;
	int			block_size;
	double		scaling;
	int			render_x;
	int			render_y;
	t_mmplayer	mmplayer;
	t_img		img;
}	t_minimap;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_gun_anim
{
	int		is_animating;
	int		frame;
	int		frame_max;
	double	frame_timer;
	double	frame_duration;
}	t_gun_anim;

typedef struct s_cub3d
{
	t_config		config;
	t_mlx			mlx;
	t_img			render_img;
	t_minimap		minimap;
	t_player		player;
	t_projection	projection;
	t_ray			*rays;
	int				keys[65536];
	int				turn;
	struct timeval	last_frame;
	double			delta_time;
	t_img			east_img;
	t_img			south_img;
	t_img			west_img;
	t_img			north_img;
	t_img			*north_dst;
	t_img			*east_dst;
	t_img			*south_dst;
	t_img			*west_dst;
	t_img			*paintball_dst;
	t_img			gun_blue;
	t_img			gun_purple;
	t_img			gun_yellow;
	t_img			gun_green;
	t_img			*current_gun;
	int				color_changed;
	int				gun_close;
	int				watch_gun_close;
	t_gun_anim		gun_anim;
}	t_cub3d;

#endif
