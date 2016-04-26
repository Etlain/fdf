/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/26 17:45:19 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		pos_fin(t_2pos *p, int zoom, int height, int b)
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

static t_pos	square(void **param, t_pos init, t_line *l1, t_line *l2)
{
	t_2pos	p;
	int		height;

	p.init = init;
	if (l1->height >= l1->next->height)
		height = l1->next->height - l1->height;
	else
		height = l1->next->height - l1->height;
	pos_fin(&p, *(int *)param[2], height, 1);
	line(param, p, l1, l2);
	p.init = p.fin;
	if (l1->next->height > l2->next->height)
		height = l1->next->height - l2->next->height;
	else
		height = l1->next->height - l2->next->height;
	pos_fin(&p, *(int *)param[2], height, 2);
	line(param, p, l1, l2);
	return (p.init);
}

static void		init_size(void **p, t_pos *size)
{
	if (*(int *)p[2] > 0)
	{
		size->x = *(int *)p[2] * X;
		size->y = *(int *)p[2] * Y;
	}
	else
	{
		size->x = 1;
		size->y = 1;
	}
}

void			win_map(void **p, t_map *map, t_pos init)
{
	t_map	*tmp;
	t_line	*l_next;
	t_line	*l;
	t_pos	size;
	int		i;

	tmp = map;
	init_size(p, &size);
	while (tmp->next != NULL)
	{
		l = tmp->line;
		l_next = tmp->next->line;
		i = 0;
		while (l->next != NULL && init.x <= W)
		{
			init = square(p, init, l, l_next);
			l_next = l_next->next;
			l = l->next;
			i++;
		}
		init.x = init.x - size.x * (i - 1);
		init.y = init.y + size.y * (i + 1) + size.y * (l->height);
		tmp = tmp->next;
		init.y = init.y - size.y * (tmp->line->height);
	}
}
