/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:48:36 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/11 14:34:31 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>

# define ESC_KEY 53
# define RIG_KEY 124
# define LEF_KEY 123
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define M_KEY 46

# define WIDTH 1920
# define HEIGHT 1080

# define UNIT 64
# define FOV 60
# define FORWARD_SPEED 10
# define SPEED 5
# define WALL_HEIGHT 64
# define THREAD 16

# define CEILING_COLOR 0x0087CEEB
# define FLOOR_COLOR 0x004CBB17

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_point_double
{
	double		x;
	double		y;
}				t_point_d;

typedef struct	s_raycast
{
	int			x;
	int			y;
	double		dis;
	char		dir;
	t_point		p;
	int			y_texture;
}				t_raycast;

typedef struct	s_map
{
	t_point		size;
	t_point		img_size;
	char		**coor;
	char		display;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_img		*minimap;
	t_img		*map_ui;
	t_point		player;
	t_map		*map;
	double		angle;
	double		angle_between;
	int			distance_const;
	t_point		intercept;
	int			unit;
	t_img		*t[4];
}				t_wolf;

typedef struct	s_thread
{
	int			id;
	t_wolf		*w;
	double		angle;
	int			c;
}				t_thread;

t_wolf			*start_up(char *location);

void			free_wolf(t_wolf *wolf);
int				hook_close(t_wolf *wolf);
void			exit_error(t_wolf *wolf, char *msg);

int				key_press(int key, t_wolf *wolf);

void			pixel_put(t_img *img, t_point a, int color);
void			fill_area(t_img *img, t_point size, int color);
void			line_img(t_img *img, t_point a, t_point b, int color);
t_point			start_point(int x, int y);

double			keep_angle(double angle);
void			draw_square(t_img *img, t_point init, int size, int interior);
void			print_images(t_wolf *wolf);

void			mini_map(t_wolf *wolf, t_img *img, t_img *ui, t_map *map);
t_map			*get_map(t_wolf *wolf, char *file);

t_raycast		ray_casting(t_wolf *wolf, t_point p, double angle);

void			get_textures(t_wolf *w, int x, int y);
void			texture_print(t_img *img, t_raycast d, t_img *tex);

void			draw_line(t_wolf *wolf, t_raycast d, int column);
void			print_player(t_wolf *wolf, t_img *img);
void			print_image(t_wolf *wolf);
void			print_background(t_wolf *wolf, int ceil, int floor);

void			*thread_command(void *thread);
t_thread		*thread_create(t_wolf *wolf, int id);

#endif
