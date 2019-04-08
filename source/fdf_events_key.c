/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:26:08 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 10:14:24 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		mlx_key_events(int key, t_fdf *fdf)
{
	if (key == 53)
		finish(fdf);
	if (key == 51)
	{
		fdf_reset(fdf);
		fdf_make(fdf, 1);
	}
	mlx_event_size(key, fdf);
	mlx_event_move(key, fdf);
	mlx_event_view(key, fdf);
	mlx_event_rotation(key, fdf);
	return (0);
}

int		mlx_event_move(int key, t_fdf *fdf)
{
	if (key == 0)
	{
		fdf->map.move_x -= fdf->map.step;
		fdf_make(fdf, 1);
	}
	if (key == 2)
	{
		fdf->map.move_x += fdf->map.step;
		fdf_make(fdf, 1);
	}
	if (key == 1)
	{
		fdf->map.move_y += fdf->map.step;
		fdf_make(fdf, 1);
	}
	if (key == 13)
	{
		fdf->map.move_y -= fdf->map.step;
		fdf_make(fdf, 1);
	}
	return (0);
}

int		mlx_event_rotation(int key, t_fdf *fdf)
{
	if (key == 123)
	{
		fdf->map.rot_x -= 0.1;
		fdf_make(fdf, 1);
	}
	if (key == 124)
	{
		fdf->map.rot_x += 0.1;
		fdf_make(fdf, 1);
	}
	if (key == 125)
	{
		fdf->map.rot_y += 0.1;
		fdf_make(fdf, 1);
	}
	if (key == 126)
	{
		fdf->map.rot_y -= 0.1;
		fdf_make(fdf, 1);
	}
	return (0);
}

int		mlx_event_size(int key, t_fdf *fdf)
{
	if (key == 24 || key == 69)
	{
		fdf->map.step++;
		fdf_make(fdf, 1);
	}
	if (key == 27 || key == 78)
	{
		fdf->map.step -= (fdf->map.step > 0) ? 1 : 0;
		fdf_make(fdf, 1);
	}
	if (key == 121)
	{
		fdf->map.pick += 0.1;
		fdf_make(fdf, 1);
	}
	if (key == 116)
	{
		fdf->map.pick -= 0.1;
		fdf_make(fdf, 1);
	}
	return (0);
}

int		mlx_event_view(int key, t_fdf *fdf)
{
	if (key == 29)
	{
		fdf->map.view = 0;
		fdf_reset(fdf);
		fdf_make(fdf, 1);
	}
	if (key == 18)
	{
		fdf->map.view = 1;
		fdf_reset(fdf);
		fdf_make(fdf, 1);
	}
	if (key == 19)
	{
		fdf->map.view = 2;
		fdf_reset(fdf);
		fdf_make(fdf, 1);
	}
	return (0);
}
