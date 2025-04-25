/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:09 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:03:10 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_color_to_exclude(unsigned int color)
{
	if (color == 0x005B6EE1 || color == 0x005B6EDE \
	|| color == 0x005B6EDF || color == 0x005D6EDF \
	|| color == 0x005B6FE1 || color == 0x005E6EDC \
	|| color == 0x005d6fdb || color == 0x00676FD1 \
	|| color == 0x005c70de || color == 0x005c6ee0 \
	|| color == 0x005b6edd || color == 0x00626ed8 \
	|| color == 0x00656fd2 || color == 0x005c6edf)
		return (1);
	return (0);
}
