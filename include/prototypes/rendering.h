/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:11:07 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:11:08 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

// utils_shape.c
int				ft_is_pixel_in_circle(int center_x, int center_y, int x, int y);

// utils_angle.c
void			ft_normalize_rad_angle(double *rad_angle);
int				ft_is_facing_up(double rad_angle);
int				ft_is_facing_right(double angle_rad);

// utils_map.c
int				ft_is_wall_collision(t_config *config, int x, int y);
int				ft_is_out_of_map(t_config config, double x, double y);

// utils_coord.c
double			ft_find_distance(int x0, int y0, int x1, int y1);

// utils_color.c
int				ft_is_color_to_exclude(unsigned int color);

// render_game.c
void			ft_render_game(t_cub3d *cub3d);

// cast_rays.c
void			ft_cast_rays(t_ray *rays, t_cub3d *cub3d);

// find_closest_wall.c
void			ft_find_closest_wall(t_cub3d *cub3d, t_ray *ray);
void			ft_find_next_inter(double *x, double *y, \
	double dist_x_next_inter, double dist_y_next_inter);

// find_closest_horizontal_wall.c
double			ft_find_closest_horizontal_wall(t_cub3d *cub3d, t_ray *ray, \
	t_player *player, double *hit_xy);
int				ft_is_ray_perfect_horizontal(double rad_angle);

// find_closest_vertical_wall.c
double			ft_find_closest_vertical_wall(t_cub3d *cub3d, t_ray *ray, \
	t_player *player, double *hit_xy);
int				ft_is_ray_perfect_vertical(double rad_angle);

// render_minimap.c
void			ft_render_minimap(t_cub3d *cub3d, t_ray *rays);

// render_walls.c
void			ft_draw_wall_column(t_cub3d *cub3d, t_ray *ray, int x);

// get_wall_text_pixel_color.c
unsigned int	ft_get_texture_pixel_color(t_cub3d *cub3d, t_img *img, \
	t_ray *ray, int render_y);

// render_game_assets.c
void			ft_render_game_assets(t_cub3d *cub3d, t_ray *rays);

// render_minimap_walls.c
void			ft_draw_minimap(t_minimap *minimap, t_config *config);

// render_minimap_rays.c
void			ft_render_minimap_rays(t_ray *rays, t_cub3d *cub3d);

// render.shapes.c
void			ft_draw_rectangle(t_img *img, int coord_xy[2], \
	int size_wh[2], int color);
void			ft_draw_circle(t_img *img, int coord_xy[2], \
	int radius, int color);

// render_bresenham_line.c
void			ft_draw_line(t_img *img, int start_xy[2], int end_xy[2], \
	int color);

// render_gun.c
void			ft_render_gun(t_cub3d *cub3d);

#endif