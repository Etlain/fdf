/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/26 17:51:15 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_hook(void)
{
	exit(0);
	return (0);
}

int		expose_hook(t_env *env)
{
	if (*(int *)env->p[5] == 1)
	{
		win_map(env->p, env->map, *env->init);
		*(int *)env->p[5] = 0;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->init->x = x;
		env->init->y = y;
		*(int *)env->p[5] = 1;
		redraw(env);
	}
	return (0);
}

void	direction(int keycode, t_env *env)
{
	if (keycode == 123)
		env->init->x = env->init->x + 10;
	if (keycode == 124)
		env->init->x = env->init->x - 10;
	if (keycode == 125)
		env->init->y = env->init->y - 10;
	if (keycode == 126)
		env->init->y = env->init->y + 10;
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_clear_window(env->p[0], env->p[1]);
		free_lst(env->map);
		exit(0);
	}
	else if (keycode == 116 && *(int *)env->zoom < 100)
	{
		*(int *)env->zoom = *(int *)env->zoom + 1;
		*(int *)env->p[5] = 1;
	}
	else if (keycode == 121 && *(int *)env->zoom > 0)
	{
		*(int *)env->zoom = *(int *)env->zoom - 1;
		*(int *)env->p[5] = 1;
	}
	direction(keycode, env);
	if (keycode >= 123 && keycode <= 126)
		*(int *)env->p[5] = 1;
	redraw(env);
	return (0);
}
