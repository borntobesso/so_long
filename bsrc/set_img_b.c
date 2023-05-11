/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:11:08 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 15:59:48 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_img_b(t_bimg *img)
{
	if (img->img_0)
		mlx_destroy_image(img->mlx, img->img_0);
	if (img->img_1)
		mlx_destroy_image(img->mlx, img->img_1);
	if (img->img_e)
		mlx_destroy_image(img->mlx, img->img_e);
	if (img->img_p_w)
		mlx_destroy_image(img->mlx, img->img_p_w);
	if (img->img_p_s)
		mlx_destroy_image(img->mlx, img->img_p_s);
	if (img->img_p_a)
		mlx_destroy_image(img->mlx, img->img_p_a);
	if (img->img_p_d)
		mlx_destroy_image(img->mlx, img->img_p_d);
}

void	destroy_img_b_2(t_bimg *img)
{
	if (img->img_c1)
		mlx_destroy_image(img->mlx, img->img_c1);
	if (img->img_c2)
		mlx_destroy_image(img->mlx, img->img_c2);
	if (img->img_c3)
		mlx_destroy_image(img->mlx, img->img_c3);
	if (img->img_c4)
		mlx_destroy_image(img->mlx, img->img_c4);
	if (img->img_c5)
		mlx_destroy_image(img->mlx, img->img_c5);
	if (img->img_c6)
		mlx_destroy_image(img->mlx, img->img_c6);
	if (img->img_c7)
		mlx_destroy_image(img->mlx, img->img_c7);
	if (img->img_c8)
		mlx_destroy_image(img->mlx, img->img_c8);
	if (img->img_b)
		mlx_destroy_image(img->mlx, img->img_b);
}

void	check_img_set_b(t_bimg *img)
{
	if (img->img_0 == NULL | img->img_1 == NULL | img->img_c1 == NULL | \
		img->img_c2 == NULL | img->img_c3 == NULL | img->img_c4 == NULL | \
		img->img_c5 == NULL | img->img_c6 == NULL | img->img_c7 == NULL | \
		img->img_c8 == NULL | img->img_e == NULL | img->img_p_s == NULL | \
		img->img_p_w == NULL | img->img_p_a == NULL | img->img_p_d == NULL | \
		img->img_b == NULL)
		ft_error_b(img, "Can't find one or more image!\n", 1);
}

void	set_img_info_b(t_bimg *img)
{
	int	height;
	int	width;

	height = HEIGHT;
	width = WIDTH;
	img->img_0 = mlx_xpm_file_to_image(img->mlx, "./img/0.xpm", \
	&width, &height);
	img->img_1 = mlx_xpm_file_to_image(img->mlx, "./img/1.xpm", \
	&width, &height);
	img->img_e = mlx_xpm_file_to_image(img->mlx, "./img/E.xpm", \
	&width, &height);
	img->img_p_s = mlx_xpm_file_to_image(img->mlx, "./img/P_S.xpm", \
	&width, &height);
	img->img_p_w = mlx_xpm_file_to_image(img->mlx, "./img/P_W.xpm", \
	&width, &height);
	img->img_p_a = mlx_xpm_file_to_image(img->mlx, "./img/P_A.xpm", \
	&width, &height);
	img->img_p_d = mlx_xpm_file_to_image(img->mlx, "./img/P_D.xpm", \
	&width, &height);
	img->img_b = mlx_xpm_file_to_image(img->mlx, "./img_b/B.xpm", \
	&width, &height);
}

void	set_img_info_b_2(t_bimg *img)
{
	int	height;
	int	width;

	height = HEIGHT;
	width = WIDTH;
	img->img_c1 = mlx_xpm_file_to_image(img->mlx, "./img_b/C1.xpm", \
	&width, &height);
	img->img_c2 = mlx_xpm_file_to_image(img->mlx, "./img_b/C2.xpm", \
	&width, &height);
	img->img_c3 = mlx_xpm_file_to_image(img->mlx, "./img_b/C3.xpm", \
	&width, &height);
	img->img_c4 = mlx_xpm_file_to_image(img->mlx, "./img_b/C4.xpm", \
	&width, &height);
	img->img_c5 = mlx_xpm_file_to_image(img->mlx, "./img_b/C5.xpm", \
	&width, &height);
	img->img_c6 = mlx_xpm_file_to_image(img->mlx, "./img_b/C6.xpm", \
	&width, &height);
	img->img_c7 = mlx_xpm_file_to_image(img->mlx, "./img_b/C7.xpm", \
	&width, &height);
	img->img_c8 = mlx_xpm_file_to_image(img->mlx, "./img_b/C8.xpm", \
	&width, &height);
}
