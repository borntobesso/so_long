/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:29:06 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 11:40:15 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_img(t_img *img)
{
	if (img->img_0)
		mlx_destroy_image(img->mlx, img->img_0);
	if (img->img_1)
		mlx_destroy_image(img->mlx, img->img_1);
	if (img->img_c)
		mlx_destroy_image(img->mlx, img->img_c);
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

void	destroy_mlx(t_img *img)
{
	mlx_destroy_display(img->mlx);
	free(img->mlx);
}

void	check_img_set(t_img *img)
{
	if (img->img_0 == NULL | img->img_1 == NULL | img->img_c == NULL | \
		img->img_e == NULL | img->img_p_s == NULL | img->img_p_w == NULL | \
		img->img_p_a == NULL | img->img_p_d == NULL)
		ft_error(img, "Can't find one or more image!\n", 1);
}

void	set_img_info(t_img *img)
{
	int	height;
	int	width;

	height = HEIGHT;
	width = WIDTH;
	img->img_0 = mlx_xpm_file_to_image(img->mlx, "./img/0.xpm", \
	&width, &height);
	img->img_1 = mlx_xpm_file_to_image(img->mlx, "./img/1.xpm", \
	&width, &height);
	img->img_c = mlx_xpm_file_to_image(img->mlx, "./img/C.xpm", \
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
}
