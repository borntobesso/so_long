/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_env_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:04:18 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 18:17:29 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img_0_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_0, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_1_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_1, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_e_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_e, \
	x * HEIGHT, y * WIDTH);
}

void	put_img_b_b(t_bimg *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_b, \
	x * HEIGHT, y * WIDTH);
}
