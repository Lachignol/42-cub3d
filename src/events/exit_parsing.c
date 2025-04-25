/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:04:15 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:04:16 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_clean_cub3d(t_cub3d *cub3d)
{
	ft_clean_cub3d(cub3d);
	exit(EXIT_FAILURE);
}

void	ft_clean_gnl(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_exit_gnl_cub3d(char *line, int fd, t_cub3d *cub3d)
{
	ft_clean_gnl(line, fd);
	ft_clean_cub3d(cub3d);
	exit(EXIT_FAILURE);
}
