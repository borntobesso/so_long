/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:44:28 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:13:33 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_mlx_b(t_bimg *img)
{
	mlx_destroy_display(img->mlx);
	free(img->mlx);
}

int	valid_arg(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (i <= 3)
	{
		printf("%sError\n", RED);
		printf("%sThe argument is not valid.\n%s", YELLOW, NORMAL);
		exit (1);
	}
	else if (file[i] != 'r' || file[i - 1] != 'e' || file[i - 2] != 'b' || \
		file[i - 3] != '.' || file[i - 4] == '/' || file[i - 4] == '.')
	{
		printf("%sError\n", RED);
		printf("%sThe argument is not valid.\n%s", YELLOW, NORMAL);
		exit (1);
	}
	return (1);
}

void	ft_init_img_b(t_bimg *img)
{
	img->mlx = NULL;
	img->win = NULL;
	img->x = 0;
	img->y = 0;
	img->map = NULL;
	img->img_0 = NULL;
	img->img_1 = NULL;
	img->img_e = NULL;
	img->img_p_s = NULL;
	img->img_p_w = NULL;
	img->img_p_a = NULL;
	img->img_p_d = NULL;
	img->collect = 0;
	img->move = 0;
	img->pos_x = 0;
	img->pos_y = 0;
}

void	ft_init_img_b_2(t_bimg *img)
{
	img->img_c1 = NULL;
	img->img_c2 = NULL;
	img->img_c3 = NULL;
	img->img_c4 = NULL;
	img->img_c5 = NULL;
	img->img_c6 = NULL;
	img->img_c7 = NULL;
	img->img_c8 = NULL;
	img->img_b = NULL;
	img->b_x = 0;
	img->b_y = 0;
}

void	init_player_pos_b(t_bimg *img)
{
	int		i;
	int		j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'P')
			{
				img->pos_x = j;
				img->pos_y = i;
			}
			else if (img->map[i][j] == 'B')
			{
				img->b_x = j;
				img->b_y = i;
			}
			j++;
		}
		i++;
	}
}
