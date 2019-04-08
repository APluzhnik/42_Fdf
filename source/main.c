/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/04/08 10:19:27 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = ft_memalloc(sizeof(t_fdf));
	fdf_init_data(fdf);
	if (argc != 2)
		die("Usage: ./fdf [file_name]");
	fdf->fd = open(argv[1], O_RDONLY);
	if (fdf->fd < 0)
		die("Error: invalid file");
	fdf_read_file(fdf);
	close(fdf->fd);
	fdf_map(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, argv[1]);
	fdf_make(fdf, 0);
	system("afplay music/sound.mp3&");
	mlx_hook(fdf->win, 2, 0, mlx_key_events, fdf);
	mlx_hook(fdf->win, 4, 0, mlx_mouse_events, fdf);
	mlx_hook(fdf->win, 17, 0, finish, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

int		die(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

int		finish(t_fdf *fdf)
{
	fdf_free_coord(fdf, 1);
	fdf_free_coord(fdf, 2);
	free(fdf->string);
	free(fdf);
	system("killall afplay");
	exit(EXIT_SUCCESS);
}

void	fdf_init_data(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->string = NULL;
	fdf->fd = -1;
	fdf->map.width = 0;
	fdf->map.height = 0;
	fdf->map.angle = 0;
	fdf->map.view = 0;
	fdf_reset(fdf);
}

void	fdf_reset(t_fdf *fdf)
{
	fdf->map.step = 20;
	fdf->map.move_x = 0;
	fdf->map.move_y = 0;
	fdf->map.pick = -0.1;
	fdf->map.rot_x = 0.1;
	fdf->map.rot_y = -0.1;
}
