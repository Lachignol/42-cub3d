/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:07 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:08 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_firearm(t_cub3d *cub3d)
{
	cub3d->gun_anim.frame_timer += cub3d->delta_time;
	if (cub3d->gun_anim.frame_timer >= cub3d->gun_anim.frame_duration)
	{
		cub3d->gun_anim.frame++;
		cub3d->gun_anim.frame_timer = 0.0;
		if (cub3d->gun_anim.frame >= cub3d->gun_anim.frame_max)
		{
			cub3d->gun_anim.is_animating = 0;
			cub3d->gun_anim.frame = 0;
		}
	}
}
