/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:06:01 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:06:21 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_isextension(const char *filename, const char *extension)
{
	const char	*file_extension;

	file_extension = ft_strrchr(filename, '.');
	if (!file_extension)
		return (0);
	if (ft_strlen(file_extension) != ft_strlen(extension))
		return (0);
	if (ft_strcmp(file_extension, extension) != 0)
		return (0);
	return (1);
}

void	ft_check_file_and_extension(const char *file_path, \
const char *extension)
{
	if (!file_path || file_path[0] == '\0')
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Empty or NULL file path provided: ", STDERR_FILENO);
		ft_putstr_fd((char *)file_path, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_isextension(file_path, extension))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Invalid file extension. Expected '", STDERR_FILENO);
		ft_putstr_fd((char *)extension, STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
