/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/02 22:33:44 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	expose_hook(t_env *env)
{
	win_map(env->p, env->map, *env->init);
	return(0);
}

int	key_hook(int keycode, t_env *env)
{
	void	*img;

	if (keycode == 53)
		exit(0);
	if (keycode == 116 && *(int *)env->zoom < 100)
		*(int *)env->zoom = *(int *)env->zoom + 1;
	if (keycode == 121 && *(int *)env->zoom > 0)
		*(int *)env->zoom = *(int *)env->zoom - 1;
	if (keycode == 123)
		env->init->x = env->init->x + 10;
	if (keycode == 124)
		env->init->x = env->init->x - 10;
	if (keycode == 125)
		env->init->y = env->init->y - 10;
	if (keycode == 126)
		env->init->y = env->init->y + 10;
	mlx_do_key_autorepeaton(env->p[0]);
	redraw(env);
	return (1);
}
