/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/03 15:42:58 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	redraw(t_env *env)
{
	void *img;

	img = mlx_new_image(env->p[0], W + 2, H + 2);
	mlx_put_image_to_window(env->p[0], env->p[1], img, -1, -1);
	mlx_destroy_image(env->p[0], img);
}

void	draw_fdf(t_map *map, void **param)
{
	t_pos	init;
	t_env	env;
	int	zoom;
	int	p_color;

	zoom = 4;
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], W, H, "FDF");
	param[2] = &zoom;
	param[3] = &p_color;
	env.map = map;
	env.p = param;
	env.init = &init;
	env.zoom = &zoom;
	init.x = 200;
	init.y = 200;
	mlx_key_hook(param[1], key_hook, (void *)&env);
	mlx_loop_hook(param[0], expose_hook, (void *)&env);
	mlx_loop(param[0]);
}
