/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/02 22:42:08 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	color(void **p , int x, int *color, int *color2)
{
	if (x <= *(int*)p[3] && *color != WHITE)
			p[4] = (void *)color;
		else if (x > *(int*)p[3] && *color2 != WHITE)
			p[4] = (void *)color2;
		else
			p[4] = NULL;
}

void		pixel_c(t_2pos pt, t_line *l1, t_line *l2, void **p)
{
	if (pt.init.y > pt.fin.y)
		color(p, pt.init.x, &l1->color, &l1->next->color);
	else if (pt.init.x == pt.fin.x)
		color(p, pt.init.y, &l1->next->color, &l2->color);
	else if (pt.init.y < pt.fin.y)
		color(p, pt.init.x, &l1->next->color, &l2->next->color);
	if (p[4] != NULL)
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, *(int *)p[4]);
	else
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, WHITE);
}
