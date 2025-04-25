/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:09:07 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/25 17:09:08 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_malloc_double_array(char ***array, int width, int height)
{
	int	i;

	*array = malloc(sizeof(char *) * (height + 1));
	if (!*array)
		return (EXIT_FAILURE);
	i = 0;
	while (i < height + 1)
	{
		(*array)[i] = malloc(sizeof(char) * (width + 1));
		if (!(*array)[i])
		{
			ft_free_double_array(*array);
			return (EXIT_FAILURE);
		}
		ft_bzero((*array)[i], width + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_free_double_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
