/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/02 03:55:35 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_2pos *p, int zoom, int height, int b)
{
	t_pos lgt;

	if (zoom == 0)
	{
		lgt.x = 1;
		lgt.y = 1 * (height + 1);
	}
	else
	{
		lgt.x = X * zoom;
		lgt.y = Y * zoom * (height + 1);
	}
	p->fin.x = p->init.x + lgt.x;
	if (b == 1)
		p->fin.y = p->init.y - lgt.y;
	else
		p->fin.y = p->init.y + lgt.y;
}

t_pos	square(void **param, t_pos init, t_line *l1, t_line *l2)
{
	t_pos lgt;
	t_2pos p;
	int height;
	//int zoom;

	//if ()
	p.init = init;
	if (l1->height >= l1->next->height)
		height = l1->next->height - l1->height;
	else
		height = l1->next->height - l1->height;
	/*lgt.x = X * 1; // (1 dans **param length p[2])
	lgt.y = Y * 1 * (height + 1);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y - lgt.y;*/
	draw(&p, *(int *)param[2], height, 1);
	line(param, p, l1, l2);
	p.init = p.fin;
	if (l1->next->height > l2->next->height)
		height = l1->next->height - l2->next->height;
	else
		height = l1->next->height - l2->next->height;
	/*lgt.y = Y * 1 * (height + 1);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y + lgt.y;*/
	draw(&p, *(int *)param[2], height, 2);
	line(param, p, l1, l2);
	return (p.init);
}

void	win_map(void **p, t_map *map, t_pos init)
{
	t_map *tmp;
	t_line *l_next;
	t_line *l;
	int i;
	int zoom;

	tmp = map;
	zoom = *(int *)p[2];
	while (tmp->next != NULL)
	{
		l = tmp->line;
		l_next = tmp->next->line;
		i = 0;
		while (l->next != NULL)
		{
			init = square(p, init, l, l_next);
			l_next = l_next->next;
			l = l->next;
			i++;
		}
		init.x = init.x - X * zoom * (i - 1);
		init.y = init.y + Y * zoom * (i + 1) + Y * zoom * (l->height);
		tmp = tmp->next;
		init.y = init.y - Y * zoom * (tmp->line->height);
	}
}
