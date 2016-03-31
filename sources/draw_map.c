/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/31 03:37:00 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pos	square(void **param, t_pos init, t_line *l1, t_line *l2)
{
	t_pos lgt;
	t_2pos p;
	int height;

	p.init = init;
	if (l1->height >= l1->next->height)
		height = l1->next->height - l1->height;
	else
		height = l1->next->height - l1->height;
	lgt.x = 11 * 1; // (1 dans **param length p[2])
	lgt.y = 5 * 1 * (height + 1);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y - lgt.y;
	line(param, p, l1, l2);
	p.init = p.fin;
	if (l1->next->height > l2->next->height)
		height = l1->next->height - l2->next->height;
	else
		height = l1->next->height - l2->next->height;
	lgt.y = 5 * 1 * (height + 1);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y + lgt.y;
	line(param, p, l1, l2);
	return (p.init);
}

void	win_map(void **p, t_map *map, t_pos init)
{
	t_map *tmp;
	t_line *l_next;
	t_line *l;
	int i;

	tmp = map;
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
		init.x = init.x - 11 * 1 * (i - 1);
		init.y = init.y + 5 * 1 * (i + 1) + 5 * 1 * (l->height);
		tmp = tmp->next;
		init.y = init.y - 5 * 1 * (tmp->line->height);
	}
}
