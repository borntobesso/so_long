/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:35:29 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:14:41 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_all_b(t_bimg *img)
{
	destroy_img_b(img);
	destroy_img_b_2(img);
	mlx_destroy_window(img->mlx, img->win);
	destroy_mlx_b(img);
	free_map_b(img);
}

void	map_up_b(t_bimg *img)
{
	int	p_x;
	int	p_y;

	p_x = img->pos_x;
	p_y = img->pos_y;
	if (img->map[p_y - 1][p_x] == 'E' && img->collect == 0)
		fin_game_b(img);
	else if (img->map[p_y - 1][p_x] == 'B')
		fin_enemy(img);
	else if (p_y - 1 >= 0 && img->map[p_y - 1][p_x] != '1' && \
		img->map[p_y - 1][p_x] != 'E')
	{
		img->map[p_y][p_x] = '0';
		img->move++;
		if (img->map[p_y - 1][p_x] == 'C')
			img->collect--;
		img->map[p_y - 1][p_x] = 'P';
		img->pos_y = p_y - 1;
		prt_msg_b(img);
	}
}

void	map_down_b(t_bimg *img)
{
	int	p_x;
	int	p_y;

	p_x = img->pos_x;
	p_y = img->pos_y;
	if (img->map[p_y + 1][p_x] == 'E' && img->collect == 0)
		fin_game_b(img);
	else if (img->map[p_y + 1][p_x] == 'B')
		fin_enemy(img);
	else if (p_y + 1 <= img->y && img->map[p_y + 1][p_x] != '1' && \
		img->map[p_y + 1][p_x] != 'E')
	{
		img->map[p_y][p_x] = '0';
		img->move++;
		if (img->map[p_y + 1][p_x] == 'C')
			img->collect--;
		img->map[p_y + 1][p_x] = 'P';
		img->pos_y = p_y + 1;
		prt_msg_b(img);
	}
}

void	map_left_b(t_bimg *img)
{
	int	p_x;
	int	p_y;

	p_x = img->pos_x;
	p_y = img->pos_y;
	if (img->map[p_y][p_x - 1] == 'E' && img->collect == 0)
		fin_game_b(img);
	else if (img->map[p_y][p_x - 1] == 'B')
		fin_enemy(img);
	else if (p_x - 1 >= 0 && img->map[p_y][p_x - 1] != '1' && \
		img->map[p_y][p_x - 1] != 'E')
	{
		img->map[p_y][p_x] = '0';
		img->move++;
		if (img->map[p_y][p_x - 1] == 'C')
			img->collect--;
		img->map[p_y][p_x - 1] = 'P';
		img->pos_x = p_x - 1;
		prt_msg_b(img);
	}
}

void	map_right_b(t_bimg *img)
{
	int	p_x;
	int	p_y;

	p_x = img->pos_x;
	p_y = img->pos_y;
	if (img->map[p_y][p_x + 1] == 'E' && img->collect == 0)
		fin_game_b(img);
	else if (img->map[p_y][p_x + 1] == 'B')
		fin_enemy(img);
	else if (p_x + 1 <= img->x && img->map[p_y][p_x + 1] != '1' && \
		img->map[p_y][p_x + 1] != 'E')
	{
		img->map[p_y][p_x] = '0';
		img->move++;
		if (img->map[p_y][p_x + 1] == 'C')
			img->collect--;
		img->map[p_y][p_x + 1] = 'P';
		img->pos_x = p_x + 1;
		prt_msg_b(img);
	}
}
