/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:09:17 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:09:18 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_system_error(char *message)
{
	write(STDERR_FILENO, "Error\n", 6);
	perror(message);
}

void	ft_print_map_error(char *message)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, "Invalid map: ", 13);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
}

void	ft_print_error(char *message)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
}
