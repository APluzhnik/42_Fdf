/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:26:08 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/04 15:50:36 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_read_file(t_fdf *fdf)
{
	char	*buff;
	char	*tmp;

	fdf->string = ft_strnew(1);
	while (get_next_line(fdf->fd, &buff) > 0)
	{
		tmp = fdf->string;
		fdf->string = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = fdf->string;
		fdf->string = ft_strjoin(tmp, "\n");
		free(tmp);
		fdf->map.height++;
		free(buff);
	}
	if (!(ft_strlen(fdf->string)))
	{
		free(fdf->string);
		die("Warning! Empty map");
	}
	fdf_width(fdf);
}

void	fdf_map(t_fdf *fdf)
{
	INIT;
	fdf->coord = ft_memalloc(sizeof(t_coord*) * fdf->map.height);
	while (fdf->string[++fdf->tmp.i])
	{
		fdf->tmp.x = 0;
		fdf->coord[fdf->tmp.y] = ft_memalloc(sizeof(t_coord) * fdf->map.width);
		while (STR != '\0' && STR != '\n')
		{
			W_INV;
			SPACE;
			if (IS_NUM || IS_SIGN)
			{
				fdf->tmp.j = fdf->tmp.i;
				while (IS_SIGN)
					fdf->tmp.i++;
				while (IS_NUM)
					fdf->tmp.i++;
				W_LARGE;
				WRITE_COORD;
				fdf->tmp.x++;
			}
		}
		W_UNEVEN;
		fdf->tmp.y++;
	}
}

void	fdf_parallel_projection(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	fdf->new_coord = ft_memalloc(sizeof(t_new_coord*) * fdf->map.height);
	while (++y < fdf->map.height)
	{
		x = -1;
		fdf->new_coord[y] = ft_memalloc(sizeof(t_new_coord) * fdf->map.width);
		while (++x < fdf->map.width)
		{
			fdf->new_coord[y][x].x = ((fdf->coord[y][x].x - fdf->coord[y][x].y
			- fdf->map.width / 2) * cos(fdf->map.rot_x)
			+ fdf->coord[y][x].z * -fdf->map.pick * sin(fdf->map.rot_x))
			* fdf->map.step + WIN_W / 2 + fdf->map.move_x;
			fdf->new_coord[y][x].y = ((fdf->coord[y][x].y + fdf->coord[y][x].z
			* fdf->map.pick - fdf->map.height / 2) * cos(fdf->map.rot_y)
			+ fdf->coord[y][x].z * -fdf->map.pick * sin(fdf->map.rot_y))
			* fdf->map.step + WIN_H / 3 + fdf->map.move_y;
		}
	}
}

void	fdf_isometric_projection(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	fdf->new_coord = ft_memalloc(sizeof(t_new_coord*) * fdf->map.height);
	while (++y < fdf->map.height)
	{
		x = -1;
		fdf->new_coord[y] = ft_memalloc(sizeof(t_new_coord) * fdf->map.width);
		while (++x < fdf->map.width)
		{
			fdf->new_coord[y][x].x = ((fdf->coord[y][x].x - fdf->coord[y][x].y
			- fdf->map.width / 2) * cos(fdf->map.rot_x)
			+ fdf->coord[y][x].z * -fdf->map.pick * sin(fdf->map.rot_x))
			* fdf->map.step + WIN_W / 2 + fdf->map.move_x;
			fdf->new_coord[y][x].y = ((-fdf->coord[y][x].z * -fdf->map.pick
			+ fdf->coord[y][x].x + fdf->coord[y][x].y - fdf->map.height / 2)
			* cos(fdf->map.rot_y)
			+ fdf->coord[y][x].z * -fdf->map.pick * sin(fdf->map.rot_y))
			* fdf->map.step + WIN_H / 4 + fdf->map.move_y;
		}
	}
}

void	fdf_normal_projection(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	fdf->new_coord = ft_memalloc(sizeof(t_new_coord*) * fdf->map.height);
	while (++y < fdf->map.height)
	{
		x = -1;
		fdf->new_coord[y] = ft_memalloc(sizeof(t_new_coord) * fdf->map.width);
		while (++x < fdf->map.width)
		{
			fdf->new_coord[y][x].x = ((fdf->coord[y][x].x -
			fdf->map.width / 2) * cos(fdf->map.rot_x)
			+ fdf->coord[y][x].z * -fdf->map.pick * sin(fdf->map.rot_x))
			* fdf->map.step + WIN_W / 2 + fdf->map.move_x;
			fdf->new_coord[y][x].y = ((fdf->coord[y][x].y
			- fdf->map.height / 2) * cos(fdf->map.rot_y)
			+ fdf->coord[y][x].z * -fdf->map.pick * sin(fdf->map.rot_y))
			* fdf->map.step + WIN_H / 2 + fdf->map.move_y;
		}
	}
}
