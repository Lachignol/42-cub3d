/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:00:48 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:00:50 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (ac != 2)
	{
		ft_print_error("Invalid number of arguments. \
Usage: ./cub3d <map_file.cub>");
		return (EXIT_FAILURE);
	}
	ft_bzero(&cub3d, sizeof(t_cub3d));
	ft_init_config(&cub3d.config, av[1]);
	ft_parse_map_file(&cub3d);
	ft_init_game(&cub3d);
	ft_render_game(&cub3d);
	mlx_loop(cub3d.mlx.mlx_ptr);
	ft_clean_all(&cub3d);
	return (EXIT_SUCCESS);
}
