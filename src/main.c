/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:30:46 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 11:31:39 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_img	img;

	if (argc == 2 && valid_arg(argv[1]))
	{
		ft_init_img(&img);
		img.mlx = mlx_init();
		img.map = ft_parsing(argv[1], &img);
		init_player_pos(&img);
		img.win = mlx_new_window(img.mlx, img.x * WIDTH, img.y * HEIGHT, \
		"**		**	*	Zero Gravity	*	**		**");
		set_img_info(&img);
		check_img_set(&img);
		init_screen(&img);
		mlx_hook(img.win, 2, 1L << 0, hook_key, &img);
		mlx_hook(img.win, 17, 0, close_mouse, &img);
		mlx_loop(img.mlx);
		destroy_all(&img);
	}
	return (0);
}
