/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:49:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/04 16:23:59 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WIN_W		1500
# define WIN_H		1000

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define DARK_GRAY	0x101010
# define GRAY		0x424242
# define BLUE		0x0000FF
# define GREEN		0x00FF00
# define RED		0xFF0000

# define STR		fdf->string[fdf->tmp.i]
# define STRN		fdf->string[fdf->tmp.j]
# define STR_PLUS	fdf->string[++fdf->tmp.i]

# define IS_NUM		(STR >= 48 && STR <= 57)
# define IS_WHITE	(STR >= 9 && STR <= 13)
# define IS_SIGN	STR == 45 || STR == 43

# define W_LARGE	if ((fdf->tmp.i - fdf->tmp.j) > 5) W_LARGE1
# define W_LARGE1	die("warning! Too large coordinats");
# define W_UNEVEN	if (fdf->tmp.x != fdf->map.width) W_UNEVEN1
# define W_UNEVEN1	die("Warning! Uneven map");
# define W_INV0		STR != 45 && STR != 43 && STR != 32
# define W_INV		if (!IS_WHITE && !IS_NUM && W_INV0) W_INV1;
# define W_INV1		die("Error: invalid map");
# define INIT		fdf->tmp.i = -1; fdf->tmp.j = 0; fdf->tmp.y = 0;

# define WRITE_COORD COORD_X COORD_Y COORD_Z
# define COORD_X	fdf->coord[fdf->tmp.y][fdf->tmp.x].x = fdf->tmp.x;
# define COORD_Y	fdf->coord[fdf->tmp.y][fdf->tmp.x].y = fdf->tmp.y;
# define COORD_Z	fdf->coord[fdf->tmp.y][fdf->tmp.x].z = ft_atoi(&STRN);

# define SPACE		if (IS_WHITE || STR == 32) fdf->tmp.i++;
# define WIDTH		ft_itoa(fdf->map.width)
# define HEIGHT		ft_itoa(fdf->map.height)

typedef struct	s_map
{
	int			width;
	int			height;
	int			angle;
	int			view;
	int			step;
	int			move_x;
	int			move_y;
	double		rot_x;
	double		rot_y;
	double		pick;
}				t_map;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_new_coord
{
	double		y;
	double		z;
	double		x;
}				t_new_coord;

typedef struct	s_line
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			del_x;
	int			del_y;
	int			sign_x;
	int			sign_y;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_tmp
{
	int			x;
	int			y;
	int			i;
	int			j;
}				t_tmp;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			fd;
	char		*string;
	t_coord		**coord;
	t_new_coord	**new_coord;
	t_map		map;
	t_line		line;
	t_tmp		tmp;
}				t_fdf;

/*
** System
*/
int				die(char *error);
void			fdf_init_data(t_fdf *fdf);
void			fdf_reset(t_fdf *fdf);
int				finish(t_fdf *fdf);
/*
** Read
*/
void			fdf_read_file(t_fdf *fdf);
void			fdf_map(t_fdf *fdf);
void			fdf_parallel_projection(t_fdf *fdf);
void			fdf_isometric_projection(t_fdf *fdf);
void			fdf_normal_projection(t_fdf *fdf);
/*
** Draw
*/
void			fdf_make(t_fdf *fdf, int f);
void			fdf_text(t_fdf *fdf);
int				fdf_color(t_fdf *fdf, int y, int x, int t);
void			fdf_render(t_fdf *fdf);
void			mlx_line(t_fdf *fdf, int color);
/*
** Key event
*/
int				mlx_key_events(int key, t_fdf *fdf);
int				mlx_event_move(int key, t_fdf *fdf);
int				mlx_event_size(int key, t_fdf *fdf);
int				mlx_event_rotation(int key, t_fdf *fdf);
int				mlx_event_view(int key, t_fdf *fdf);
/*
** Mouse events
*/
int				mlx_mouse_events(int btn, int x, int y, t_fdf *fdf);
void			fdf_free_coord(t_fdf *fdf, int f);
void			fdf_line(t_fdf *fdf, int x, int y, int t);
void			fdf_width(t_fdf *fdf);
void			fdf_text2(t_fdf *fdf);

#endif
