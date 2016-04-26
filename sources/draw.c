/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/26 17:48:39 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	redraw(t_env *env)
{
	void *img;

	if (*(int *)env->p[5] == 0)
		return ;
	img = mlx_new_image(env->p[0], W + 2, H + 2);
	mlx_put_image_to_window(env->p[0], env->p[1], img, -1, -1);
	mlx_destroy_image(env->p[0], img);
}

void	draw_fdf(t_map *map, void **param)
{
	t_pos	init;
	t_env	env;
	int		zoom;
	int		p_color;
	int		b_draw;

	zoom = 4;
	b_draw = 1;
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], W, H, "FDF");
	param[2] = &zoom;
	param[3] = &p_color;
	param[5] = &b_draw;
	env.map = map;
	env.p = param;
	env.init = &init;
	env.zoom = &zoom;
	init.x = 200;
	init.y = 200;
	mlx_hook(param[1], 2, 1, key_hook, (void *)&env);
	mlx_hook(param[1], 17, 1, close_hook, NULL);
	mlx_mouse_hook(param[1], mouse_hook, (void *)&env);
	mlx_loop_hook(param[0], expose_hook, (void *)&env);
	mlx_loop(param[0]);
}
