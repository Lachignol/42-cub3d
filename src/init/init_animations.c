/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:09 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:08:11 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_gun_animation(t_cub3d *cub3d)
{
	cub3d->gun_anim.frame_max = GUN_ANIM_NBR_FRAMES;
	cub3d->gun_anim.frame_duration = (double)GUN_ANIM_DUR \
		/ (double)GUN_ANIM_NBR_FRAMES;
}
