/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_player_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:09:14 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 16:10:02 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img_p_s_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_s, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_p_w_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_w, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_p_a_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_a, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_p_d_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_p_d, \
	x * HEIGHT, y * WIDTH);
}
