/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:51:31 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 11:55:24 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img_p_s(t_img *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_s, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_p_w(t_img *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_w, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_p_a(t_img *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_a, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_p_d(t_img *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_d, \
	x * HEIGHT, y * WIDTH);
}
