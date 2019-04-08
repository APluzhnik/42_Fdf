/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:26:08 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/04 16:23:40 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_text(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 4;
	while (++y < 275)
	{
		x = 4;
		while (++x < 300)
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, DARK_GRAY);
	}
	mlx_string_put(fdf->mlx, fdf->win, 100, 10, WHITE, "Usage");
	mlx_string_put(fdf->mlx, fdf->win, 15, 40, WHITE, "Esc - Exit");
	mlx_string_put(fdf->mlx, fdf->win, 15, 60, WHITE, "W/A/S/D - Move");
	mlx_string_put(fdf->mlx, fdf->win, 15, 80, WHITE, "Arrows - Rotation");
	mlx_string_put(fdf->mlx, fdf->win, 15, 100, WHITE, "Scroll/+/- - Zoom");
	mlx_string_put(fdf->mlx, fdf->win, 15, 120, WHITE, "Page up/down - Height");
	mlx_string_put(fdf->mlx, fdf->win, 15, 140, WHITE, "Backspace - Reset");
	mlx_string_put(fdf->mlx, fdf->win, 15, 160, WHITE, "0/1/2 - Change view");
	mlx_string_put(fdf->mlx, fdf->win, 100, 190, WHITE, "Info");
	if (fdf->map.view == 1)
		mlx_string_put(fdf->mlx, fdf->win, 15, 210, WHITE, "View: Parallel");
	else if (fdf->map.view == 2)
		mlx_string_put(fdf->mlx, fdf->win, 15, 210, WHITE, "View: Isometric");
	else
		mlx_string_put(fdf->mlx, fdf->win, 15, 210, WHITE, "View: Normal");
}

void	fdf_render(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
			{
				fdf_line(fdf, x, y, 0);
				mlx_line(fdf, fdf_color(fdf, y, x, 1));
			}
			if (y < fdf->map.height - 1)
			{
				fdf_line(fdf, x, y, 1);
				mlx_line(fdf, fdf_color(fdf, y, x, 0));
			}
			if (fdf->map.height == 1 && fdf->map.width == 1)
				die("Warning! Add second point");
			x++;
		}
		y++;
	}
}

int		fdf_color(t_fdf *fdf, int y, int x, int t)
{
	if (t)
	{
		if (fdf->coord[y][x].z || fdf->coord[y][x + 1].z)
		{
			if (fdf->coord[y][x].z == fdf->coord[y][x + 1].z)
				return (RED);
			if (fdf->coord[y][x].z || fdf->coord[y][x + 1].z)
				return (BLUE);
		}
	}
	else
	{
		if (fdf->coord[y][x].z || fdf->coord[y + 1][x].z)
		{
			if (fdf->coord[y][x].z == fdf->coord[y + 1][x].z)
				return (RED);
			if (fdf->coord[y][x].z || fdf->coord[y + 1][x].z)
				return (BLUE);
		}
	}
	return (GREEN);
}

void	mlx_line(t_fdf *fdf, int color)
{
	fdf->line.del_x = abs(fdf->line.x2 - fdf->line.x1);
	fdf->line.del_y = abs(fdf->line.y2 - fdf->line.y1);
	fdf->line.sign_x = fdf->line.x1 < fdf->line.x2 ? 1 : -1;
	fdf->line.sign_y = fdf->line.y1 < fdf->line.y2 ? 1 : -1;
	fdf->line.err = fdf->line.del_x - fdf->line.del_y;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->line.x2, fdf->line.y2, color);
	while (fdf->line.x1 != fdf->line.x2 || fdf->line.y1 != fdf->line.y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->line.x1, fdf->line.y1, color);
		if ((fdf->line.err2 = fdf->line.err * 2) > -fdf->line.del_y)
		{
			fdf->line.err -= fdf->line.del_y;
			fdf->line.x1 += fdf->line.sign_x;
		}
		if (fdf->line.err2 < fdf->line.del_x)
		{
			fdf->line.err += fdf->line.del_x;
			fdf->line.y1 += fdf->line.sign_y;
		}
	}
}

void	fdf_make(t_fdf *fdf, int f)
{
	if (f)
		fdf_free_coord(fdf, 1);
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->map.angle = 0;
	if (fdf->map.view == 1)
		fdf_parallel_projection(fdf);
	else if (fdf->map.view == 2)
		fdf_isometric_projection(fdf);
	else
		fdf_normal_projection(fdf);
	fdf_render(fdf);
	fdf_text(fdf);
	fdf_text2(fdf);
}
