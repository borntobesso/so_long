/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:02:05 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 16:56:27 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map_b(t_bimg *img)
{
	int		i;
	char	**map;

	map = img->map;
	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	free_all_split_b(char	*s, char **res, t_bimg *img, char *msg)
{
	int	i;

	i = 0;
	while (res != NULL && res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	free(s);
	ft_error_b(img, msg, 0);
}

int	line_count(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*line_malloc_b(char *s, t_bimg *img, char *map, char **res)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (img->x == 0)
		img->x = len;
	else if (img->x != len)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		free_all_split_b(map, res, img, "Problem encountered on malloc.\n");
	i = 0;
	while (*s && *s != '\n')
	{
		line[i] = *(s++);
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**ft_split_b(char *s, char c, t_bimg *img)
{
	char	**res;
	int		i;
	int		j;

	img->y = line_count(s, c);
	res = (char **)malloc(sizeof(char *) * (img->y + 1));
	if (res == NULL)
		ft_error_b(img, "Problem encountered on malloc\n", 0);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			res[i] = line_malloc_b(&s[j], img, s, res);
			if (res[i++] == NULL)
				free_all_split_b(s, res, img, "The map is not rectangular.\n");
			while (s[j] && s[j] != c)
				j++;
		}
	}
	res[i] = 0;
	return (res);
}
