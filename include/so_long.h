/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:51:40 by sojung            #+#    #+#             */
/*   Updated: 2022/02/04 14:01:36 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
/			|HEADERS|
*/

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <time.h>

/*
/			|STRUCTURES|
*/

typedef struct s_img {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	**map;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p_s;
	void	*img_p_w;
	void	*img_p_a;
	void	*img_p_d;
	int		collect;
	int		move;
	int		pos_x;
	int		pos_y;
}	t_img;

typedef struct s_bimg {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	**map;
	void	*img_0;
	void	*img_1;
	void	*img_e;
	void	*img_p_s;
	void	*img_p_w;
	void	*img_p_a;
	void	*img_p_d;
	void	*img_c1;
	void	*img_c2;
	void	*img_c3;
	void	*img_c4;
	void	*img_c5;
	void	*img_c6;
	void	*img_c7;
	void	*img_c8;
	void	*img_b;
	int		collect;
	int		move;
	int		pos_x;
	int		pos_y;
	int		b_x;
	int		b_y;
}	t_bimg;

/*
/			|MACROS|
*/

# define BUFFER_SIZE 10
# define WIDTH 64
# define HEIGHT 64

# define NORMAL "\033[0m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"

/*
/			|INIT FUCTIONS|
*/

int		valid_arg(char *file);
void	ft_init_img(t_img *img);
void	init_player_pos(t_img *img);

/*
/			|GET_NEXT_LINE FUNCTIONS|
*/

char	*get_next_line(int fd);
int		ft_chr_newline(char *buf);
char	*ft_put_line(char *buf);
char	*ft_return_left(char *buf, int index_r);
int		ft_strlen(char *s);
char	*ft_strjoin(char *left, char *buf, int flag);
char	*ft_strdup(char *s);
char	*ft_clean(char **left, char *buf);
char	*ft_joinleft(char **left, int fd);

/*
/			|SPLIT FUNCTIONS|
*/

void	free_all_split(char *s, char **res, t_img *img, char *msg);
int		line_count(char *s, char c);
char	*line_malloc(char *s, t_img *img, char *map, char **res);
char	**ft_split(char *s, char c, t_img *img);

/*
/			|PARSING FUNCTIONS|
*/

char	*read_map(char *map, t_img *img);
char	**ft_parsing(char *file, t_img *img);

/*
/			|VALID MAP FUNCTIONS|
*/

int		check_first_wall(char *map);
int		check_last_wall(char *map);
int		check_vertical_wall(char *map, int index_n);
int		check_sprite(t_img *img, char *map);
int		check_map(t_img *img, char *map);

/*
/			|IMAGE FUNCTIONS|
*/

void	check_img_set(t_img *img);
void	set_img_info(t_img *img);
void	init_screen(t_img *img);

void	put_img_0(t_img *img, int x, int y);
void	put_img_1(t_img *img, int x, int y);
void	put_img_c(t_img *img, int x, int y);
void	put_img_e(t_img *img, int x, int y);
void	put_img_p_s(t_img *img, int x, int y);
void	put_img_p_w(t_img *img, int x, int y);
void	put_img_p_a(t_img *img, int x, int y);
void	put_img_p_d(t_img *img, int x, int y);

/*
/			|MAP UPDATING FUNCTIONS|
*/

void	map_up(t_img *img);
void	map_down(t_img *img);
void	map_left(t_img *img);
void	map_right(t_img *img);

/*
/			|FINISHING FUNCTIONS|
*/

void	destroy_img(t_img *img);
void	destroy_mlx(t_img *img);
void	ft_error(t_img *img, char *msg, int flag);
void	free_map(t_img *img);
void	destroy_all(t_img *img);
void	fin_game(t_img *img);

/*
/			|HOOK FUNCTIONS|
*/

int		hook_key(int keycode, t_img *img);
int		close_mouse(t_img *img);
void	prt_msg(t_img *img);

/*
/			|BONUS FUNCTIONS|
*/

void	destroy_img_b(t_bimg *img);
void	destroy_img_b_2(t_bimg *img);
void	destroy_mlx_b(t_bimg *img);
void	ft_error_b(t_bimg *img, char *msg, int flag);
void	free_map_b(t_bimg *img);
void	destroy_all_b(t_bimg *img);
void	fin_game_b(t_bimg *img);
void	fin_enemy(t_bimg *img);

void	check_img_set_b(t_bimg *img);
void	set_img_info_b(t_bimg *img);
void	set_img_info_b_2(t_bimg *img);
void	init_screen_b(t_bimg *img, int flag);

int		hook_key_b(int keycode, t_bimg *img);
int		close_mouse_b(t_bimg *img);
void	prt_msg_b(t_bimg *img);

int		check_sprite_b(t_bimg *img, char *map);
int		check_map_b(t_bimg *img, char *map);

void	ft_init_img_b(t_bimg *img);
void	ft_init_img_b_2(t_bimg *img);
void	init_player_pos_b(t_bimg *img);

char	*read_map_b(char *map, t_bimg *img);
char	**ft_parsing_b(char *file, t_bimg *img);

void	put_img_0_b(t_bimg *img, int x, int y);
void	put_img_1_b(t_bimg *img, int x, int y);
void	put_img_b_b(t_bimg *img, int x, int y);
void	put_img_e_b(t_bimg *img, int x, int y);

void	put_img_p_s_b(t_bimg *img, int x, int y);
void	put_img_p_w_b(t_bimg *img, int x, int y);
void	put_img_p_a_b(t_bimg *img, int x, int y);
void	put_img_p_d_b(t_bimg *img, int x, int y);

void	put_img_c1(t_bimg *img, int x, int y);
void	put_img_c2(t_bimg *img, int x, int y);
void	put_img_c3(t_bimg *img, int x, int y);
void	put_img_c4(t_bimg *img, int x, int y);
void	put_img_c5(t_bimg *img, int x, int y);
void	put_img_c6(t_bimg *img, int x, int y);
void	put_img_c7(t_bimg *img, int x, int y);
void	put_img_c8(t_bimg *img, int x, int y);

void	map_up_b(t_bimg *img);
void	map_down_b(t_bimg *img);
void	map_left_b(t_bimg *img);
void	map_right_b(t_bimg *img);

int		ft_count(int n);
void	ft_set(char *s, unsigned int n, int size);
char	*ft_itoa(int n);

void	free_all_split_b(char *s, char **res, t_bimg *img, char *msg);
char	*line_malloc_b(char *s, t_bimg *img, char *map, char **res);
char	**ft_split_b(char *s, char c, t_bimg *img);
void	free_map_(t_bimg *img);

int		moving_col(t_bimg *img);
void	put_moving_col(t_bimg *img, int flag, int j, int i);
void	put_moving_blackhole(t_bimg *img, int flag);

void	change_enemy_0(t_bimg *img);
void	change_enemy_1(t_bimg *img);
void	change_enemy_2(t_bimg *img);
void	change_enemy_3(t_bimg *img);

#endif
