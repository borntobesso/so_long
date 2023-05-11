/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:29:07 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 11:24:49 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*read_map(char *file, t_img *img)
{
	int		fd;
	char	*tmp;
	char	*line;
	char	*map;

	tmp = malloc(sizeof(char) * 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{	
		free(tmp);
		ft_error(img, "Problem encountered reading the map.\n", 0);
	}
	line = get_next_line(fd);
	map = ft_strjoin(tmp, line, 1);
	while (line)
	{	
		free(line);
		line = get_next_line(fd);
		map = ft_strjoin(map, line, 1);
	}
	free(line);
	return (map);
}

char	**ft_parsing(char *file, t_img *img)
{
	char	*map;
	char	**matrix;

	map = read_map(file, img);
	if (!map)
		ft_error(img, "Problem encountered reading the map.\n", 0);
	if (check_map(img, map) == 1)
	{
		matrix = ft_split(map, '\n', img);
		free(map);
		return (matrix);
	}
	else
		return (NULL);
}
