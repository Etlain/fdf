/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/02 02:41:42 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <fcntl.h>
#include <stdio.h>

void	redraw(t_env *env)
{
	void *img;

	img = mlx_new_image(env->p[0], WIDTH, HEIGHT);
	mlx_put_image_to_window(env->p[0], env->p[1], img, 0, 0);
	mlx_destroy_image(env->p[0], img);
}

int	key_hook(int keycode, t_env *env)
{
	void *img;

	ft_putstr("\nkeycode :");
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env->init->x = env->init->x - 10;
	if (keycode == 124)
		env->init->x = env->init->x + 10;
	if (keycode == 125)
		env->init->y = env->init->y + 10;
	if (keycode == 126)
		env->init->y = env->init->y - 10;
	redraw(env);
	return (1);
}

int	expose_hook(t_env *env)
{
	win_map(env->p, env->map, *env->init);
	return(0);
}

void	draw_fdf(t_map *map, void **param)
{
	t_pos	init;
	t_env	env;

	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], WIDTH, HEIGHT, "FDF");
	env.map = map;
	env.p = param;
	env.init = &init;
	init.x = 200;
	init.y = 200;
	mlx_key_hook(param[1], key_hook, (void *)&env);
	mlx_loop_hook(param[0], expose_hook, (void *)&env);
	mlx_loop(param[0]);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	void	**param;
	int 	fd;

	if (argc != 2)
	{
		ft_putstr("error : number of parameter\n");
		return (-1);
	}
	param = (void **)malloc(sizeof(void *) * 6);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	draw_fdf(map, param);
	return (0);
}
