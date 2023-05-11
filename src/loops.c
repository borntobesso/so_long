/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:26:36 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 15:56:04 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hook_key(int keycode, t_img *img)
{
	if (keycode == 0xff1b)
	{
		destroy_all(img);
		exit (0);
	}
	else if (keycode == 0x77 || keycode == 0xff52)
		map_up(img);
	else if (keycode == 0x73 || keycode == 0xff54)
		map_down(img);
	else if (keycode == 0x61 || keycode == 0xff51)
		map_left(img);
	else if (keycode == 0x64 || keycode == 0xff53)
		map_right(img);
	return (0);
}

int	close_mouse(t_img *img)
{
	destroy_all(img);
	exit (0);
	return (0);
}
