/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:26:08 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 10:18:35 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		mlx_mouse_events(int btn, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (btn == 4)
	{
		fdf->map.step++;
		fdf_make(fdf, 1);
	}
	if (btn == 5)
	{
		fdf->map.step -= (fdf->map.step > 0) ? 1 : 0;
		fdf_make(fdf, 1);
	}
	return (0);
}

void	fdf_free_coord(t_fdf *fdf, int f)
{
	int		y;

	y = -1;
	while (++y < fdf->map.height)
	{
		if (f == 1)
			free(fdf->new_coord[y]);
		if (f == 2)
			free(fdf->coord[y]);
	}
	if (f == 1)
		free(fdf->new_coord);
	if (f == 2)
		free(fdf->coord);
}

void	fdf_line(t_fdf *fdf, int x, int y, int t)
{
	if (t)
	{
		fdf->line.x1 = fdf->new_coord[y][x].x;
		fdf->line.y1 = fdf->new_coord[y][x].y;
		fdf->line.x2 = fdf->new_coord[y + 1][x].x;
		fdf->line.y2 = fdf->new_coord[y + 1][x].y;
	}
	else
	{
		fdf->line.x1 = fdf->new_coord[y][x].x;
		fdf->line.y1 = fdf->new_coord[y][x].y;
		fdf->line.x2 = fdf->new_coord[y][x + 1].x;
		fdf->line.y2 = fdf->new_coord[y][x + 1].y;
	}
}

void	fdf_width(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (fdf->string[i] != '\n')
	{
		if (fdf->string[i] != ' ')
		{
			fdf->map.width++;
			while (fdf->string[i] != ' ' && fdf->string[i] != '\n')
				i++;
		}
		while (fdf->string[i] == ' ')
			i++;
	}
}

void	fdf_text2(t_fdf *fdf)
{
	char	*w;
	char	*h;

	w = WIDTH;
	h = HEIGHT;
	mlx_string_put(fdf->mlx, fdf->win, 15, 230, WHITE, "Width:");
	mlx_string_put(fdf->mlx, fdf->win, 150, 230, WHITE, "Length:");
	mlx_string_put(fdf->mlx, fdf->win, 100, 230, WHITE, w);
	mlx_string_put(fdf->mlx, fdf->win, 250, 230, WHITE, h);
	free(w);
	free(h);
}
