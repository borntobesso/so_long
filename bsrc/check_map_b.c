/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:08 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 17:28:17 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_first_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i--;
	while (i >= 0)
	{
		if (map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	check_last_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (map[i] == '\n')
		i--;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	check_vertical_wall(char *map, int index_n)
{
	if (map[index_n - 1] != '1' || (map[index_n + 1] != '1' && \
		map[index_n + 1] != '\0'))
		return (0);
	else
		return (1);
}

int	check_sprite_b(t_bimg *img, char *map)
{
	int	exit;
	int	empty;
	int	player;

	exit = 0;
	empty = 0;
	player = 0;
	while (*map)
	{
		if (*map == '0')
			empty++;
		else if (*map == 'E')
			exit++;
		else if (*map == 'C')
			img->collect++;
		else if (*map == 'P')
			player++;
		else if (*map != '\n' && *map != '1' && *map != 'B')
			return (-1);
		map++;
	}
	if (empty < 1 || exit < 1 || img->collect < 1 || player != 1)
		return (0);
	else
		return (1);
}

int	check_map_b(t_bimg *img, char *map)
{
	int	i;

	if (check_sprite_b(img, map) != 1)
	{
		free(map);
		ft_error_b(img, "The map has element issue(s).\n", 0);
	}
	i = -1;
	while (map[++i])
	{
		if ((map[i] == '\n' && check_vertical_wall(map, i) == 0) || \
			check_first_wall(map) == 0 || check_last_wall(map) == 0)
		{
			free(map);
			ft_error_b(img, "The map is not closed with wall.\n", 0);
		}
	}
	return (1);
}
