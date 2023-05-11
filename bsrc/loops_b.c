/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:26:36 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:09:07 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hook_key_b(int keycode, t_bimg *img)
{
	char	*move;

	put_img_1_b(img, 0, 0);
	put_img_1_b(img, WIDTH, 0);
	if (keycode == 0xff1b)
	{
		destroy_all_b(img);
		exit (0);
	}
	else if (keycode == 0x77 || keycode == 0xff52)
		map_up_b(img);
	else if (keycode == 0x73 || keycode == 0xff54)
		map_down_b(img);
	else if (keycode == 0x61 || keycode == 0xff51)
		map_left_b(img);
	else if (keycode == 0x64 || keycode == 0xff53)
		map_right_b(img);
	move = ft_itoa(img->move);
	mlx_string_put(img->mlx, img->win, 52, 50, 0xFFFFFF, move);
	free(move);
	return (0);
}

int	close_mouse_b(t_bimg *img)
{
	destroy_all_b(img);
	exit (0);
	return (0);
}

int	moving_col(t_bimg *img)
{
	clock_t	t;

	t = clock() / CLOCKS_PER_SEC;
	put_moving_blackhole(img, t % 4);
	init_screen_b(img, 1);
	return (0);
}

void	put_moving_col(t_bimg *img, int flag, int j, int i)
{
	if (flag == 0)
		put_img_c1(img, j, i);
	else if (flag == 1)
		put_img_c2(img, j, i);
	else if (flag == 2)
		put_img_c3(img, j, i);
	else if (flag == 3)
		put_img_c4(img, j, i);
	else if (flag == 4)
		put_img_c5(img, j, i);
	else if (flag == 5)
		put_img_c6(img, j, i);
	else if (flag == 6)
		put_img_c7(img, j, i);
	else if (flag == 7)
		put_img_c8(img, j, i);
}

void	put_moving_blackhole(t_bimg *img, int flag)
{
	if (flag == 0)
		change_enemy_0(img);
	else if (flag == 1)
		change_enemy_1(img);
	else if (flag == 2)
		change_enemy_2(img);
	else if (flag == 3)
		change_enemy_3(img);
}
