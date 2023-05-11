/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_enemy_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:52:36 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:10:17 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_enemy_0(t_bimg *img)
{
	if (img->map[img->b_y][img->b_x] != 'P')
		img->map[img->b_y][img->b_x] = '0';
	if (img->map[img->b_y][img->b_x + 1] == 'P')
		fin_enemy(img);
	img->map[img->b_y][img->b_x + 1] = 'B';
}

void	change_enemy_1(t_bimg *img)
{
	if (img->map[img->b_y][img->b_x + 1] != 'P')
		img->map[img->b_y][img->b_x + 1] = '0';
	if (img->map[img->b_y + 1][img->b_x + 1] == 'P')
		fin_enemy(img);
	img->map[img->b_y + 1][img->b_x + 1] = 'B';
}

void	change_enemy_2(t_bimg *img)
{
	if (img->map[img->b_y + 1][img->b_x + 1] != 'P')
		img->map[img->b_y + 1][img->b_x + 1] = '0';
	if (img->map[img->b_y + 1][img->b_x] == 'P')
		fin_enemy(img);
	img->map[img->b_y + 1][img->b_x] = 'B';
}

void	change_enemy_3(t_bimg *img)
{
	if (img->map[img->b_y + 1][img->b_x] != 'P')
		img->map[img->b_y + 1][img->b_x] = '0';
	if (img->map[img->b_y][img->b_x] == 'P')
		fin_enemy(img);
	img->map[img->b_y][img->b_x] = 'B';
}
