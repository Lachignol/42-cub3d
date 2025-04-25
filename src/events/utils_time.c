/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:37 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:38 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_get_delta_time(t_cub3d *cub3d)
{
	struct timeval	current_time;
	double			delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - cub3d->last_frame.tv_sec) + \
		(current_time.tv_usec - cub3d->last_frame.tv_usec) / 1000000.0;
	if (delta_time > 0.1)
		delta_time = 0.1;
	cub3d->last_frame = current_time;
	return (delta_time);
}
