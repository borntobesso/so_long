/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_col_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:11:16 by sojung            #+#    #+#             */
/*   Updated: 2022/02/03 10:44:40 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img_c5(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c5, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_c6(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c6, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_c7(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c7, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_c8(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c8, \
	x * HEIGHT, y * WIDTH);
}
