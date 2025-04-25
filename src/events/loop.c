/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:26 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:27 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_watch_keys_move_hero(t_cub3d *cub3d, int *has_moved)
{
	if (cub3d->keys[KEY_W] || cub3d->keys[KEY_A] || \
		cub3d->keys[KEY_S] || cub3d->keys[KEY_D])
	{
		if (ft_move_hero(cub3d) == EXIT_SUCCESS)
			*has_moved = 1;
	}
}

static void	ft_watch_keys_turn_hero(t_cub3d *cub3d, int *has_moved)
{
	if (cub3d->keys[KEY_LEFT] || cub3d->keys[KEY_RIGHT])
	{
		ft_turn_hero(cub3d);
		*has_moved = 1;
	}
}

int	ft_loop(t_cub3d *cub3d)
{
	int		has_moved;

	has_moved = 0;
	cub3d->delta_time = ft_get_delta_time(cub3d);
	ft_watch_keys_turn_hero(cub3d, &has_moved);
	ft_watch_keys_move_hero(cub3d, &has_moved);
	ft_watch_gun_distance(cub3d);
	if (cub3d->gun_anim.is_animating)
		ft_firearm(cub3d);
	if (has_moved || cub3d->turn || cub3d->color_changed \
	|| cub3d->watch_gun_close != cub3d->gun_close)
	{
		ft_render_game(cub3d);
		cub3d->turn = 0;
		cub3d->color_changed = 0;
		cub3d->watch_gun_close = cub3d->gun_close;
	}
	else if (cub3d->gun_anim.is_animating)
		ft_render_game(cub3d);
	return (EXIT_SUCCESS);
}
