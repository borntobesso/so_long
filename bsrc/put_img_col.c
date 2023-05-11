/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:10:19 by sojung            #+#    #+#             */
/*   Updated: 2022/02/03 10:44:46 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img_c1(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c1, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_c2(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c2, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_c3(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c3, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_c4(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_c4, \
	x * HEIGHT, y * WIDTH);
}
