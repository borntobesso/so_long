/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:55:19 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 13:05:50 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(t_img *img, char *msg, int flag)
{
	if (flag == 1)
	{
		destroy_img(img);
		mlx_destroy_window(img->mlx, img->win);
	}
	destroy_mlx(img);
	printf("%sError\n", RED);
	printf("%s%s%s", YELLOW, msg, NORMAL);
	exit (1);
}

void	init_screen(t_img *img)
{
	int		i;
	int		j;

	i = -1;
	while (img->map[++i])
	{
		j = -1;
		while (img->map[i][++j])
		{
			if (img->map[i][j] == '0')
				put_img_0(img, j, i);
			else if (img->map[i][j] == '1')
				put_img_1(img, j, i);
			else if (img->map[i][j] == 'C')
				put_img_c(img, j, i);
			else if (img->map[i][j] == 'E')
				put_img_e(img, j, i);
			else if (img->map[i][j] == 'P')
				put_img_p_s(img, j, i);
			else
				ft_error(img, "The map contains unknown character(s).\n", 1);
		}
	}
}

void	prt_msg(t_img *img)
{
	printf("%s*---------------------------------------*\n", CYAN);
	printf("|	Items to collect : %s%d%s		|\n", YELLOW, img->collect, \
CYAN);
	printf("|	Moves		: %s%d%s		|\n", YELLOW, img->move, CYAN);
	printf("*---------------------------------------*\n\n%s", NORMAL);
}

void	fin_game(t_img *img)
{
	put_img_0(img, img->pos_x, img->pos_y);
	prt_msg(img);
	printf("%s*--------------------------------------------------------------\
-------*\n", GREEN);
	printf("%s\n\n	Hooray! You've arrived on the Earth safely with %s%d%s \
moves!\n\n\n", GREEN, YELLOW, img->move, GREEN);
	printf("*----------------------------------------------------------------\
-----*%s\n\n", NORMAL);
	destroy_all(img);
	exit (0);
}
