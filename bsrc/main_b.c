/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:50:03 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:09:18 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_bimg	img;

	if (argc == 2 && valid_arg(argv[1]))
	{
		ft_init_img_b(&img);
		ft_init_img_b_2(&img);
		img.mlx = mlx_init();
		img.map = ft_parsing_b(argv[1], &img);
		init_player_pos_b(&img);
		img.win = mlx_new_window(img.mlx, img.x * WIDTH, img.y * HEIGHT, \
		"**		**	*	Zero Gravity	*	**		**");
		set_img_info_b(&img);
		set_img_info_b_2(&img);
		check_img_set_b(&img);
		init_screen_b(&img, 0);
		mlx_string_put(img.mlx, img.win, 52, 50, 0xFFFFFF, "0");
		mlx_loop_hook(img.mlx, moving_col, &img);
		mlx_hook(img.win, 2, 1L << 0, hook_key_b, &img);
		mlx_hook(img.win, 17, 0, close_mouse_b, &img);
		mlx_loop(img.mlx);
		destroy_all_b(&img);
	}
	return (0);
}
