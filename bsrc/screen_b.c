/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:13:08 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:13:47 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_b(t_bimg *img, char *msg, int flag)
{
	if (flag == 1)
	{
		destroy_img_b(img);
		destroy_img_b_2(img);
		mlx_destroy_window(img->mlx, img->win);
	}
	destroy_mlx_b(img);
	printf("%sError\n", RED);
	printf("%s%s%s", YELLOW, msg, NORMAL);
	exit (1);
}

void	init_screen_b(t_bimg *img, int flag)
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
				put_img_0_b(img, j, i);
			else if (img->map[i][j] == '1' && flag == 0)
				put_img_1_b(img, j, i);
			else if (img->map[i][j] == 'C')
				put_moving_col(img, clock() / CLOCKS_PER_SEC % 8, j, i);
			else if (img->map[i][j] == 'E')
				put_img_e_b(img, j, i);
			else if (img->map[i][j] == 'P')
				put_img_p_s_b(img, j, i);
			else if (img->map[i][j] == 'B')
				put_img_b_b(img, j, i);
		}
	}
}

void	prt_msg_b(t_bimg *img)
{
	printf("%s*---------------------------------------*\n", CYAN);
	printf("|	Items to collect : %s%d%s		|\n", YELLOW, img->collect, \
CYAN);
	printf("|	Moves		: %s%d%s		|\n", YELLOW, img->move, CYAN);
	printf("*---------------------------------------*\n\n%s", NORMAL);
}

void	fin_game_b(t_bimg *img)
{
	img->move++;
	put_img_0_b(img, img->pos_x, img->pos_y);
	prt_msg_b(img);
	printf("%s*--------------------------------------------------------------\
-------*\n", GREEN);
	printf("%s\n\n	Hooray! You've arrived on the Earth safely with %s%d%s \
moves!\n\n\n", GREEN, YELLOW, img->move, GREEN);
	printf("*----------------------------------------------------------------\
-----*%s\n\n", NORMAL);
	destroy_all_b(img);
	exit (0);
}

void	fin_enemy(t_bimg *img)
{
	img->move++;
	put_img_0_b(img, img->pos_x, img->pos_y);
	prt_msg_b(img);
	printf("%s*-----------------------------------------------------------*\n", \
RED);
	printf("%s\n\n	R.I.P...You've been absorbed by a blackhole!\n\n\n", \
RED);
	printf("*-----------------------------------------------------------*%s\n\n", \
NORMAL);
	destroy_all_b(img);
	exit (0);
}
