/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/14 17:29:23 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_2pos *p, int *div, int *p_color)
{
	int p_y;

	if (p->fin.y > p->init.y)
		p_y = (p->fin.y - p->init.y) + 1;
	else
		p_y = (p->init.y - p->fin.y) + 1;
	if (p->fin.x >= p->init.x)
	{
		*div = ((p->fin.x - p->init.x) + 1) / p_y;
		*p_color = p->fin.x - (p->fin.x - p->init.x) / 2;
		if (p->fin.x == p->init.x)
			*p_color = p->fin.y - (p->fin.y - p->init.y) / 2;
	}
	else
	{
		*div = ((p->init.x - p->fin.x) + 1) / p_y;
		*p_color = p->init.x - (p->init.x - p->fin.x) / 2;
	}
}

void	pixel_color(t_2pos pt, t_line *l1, t_line *l2, void **p)
{
	//ft_putstr("\npixel color :");
	if (pt.init.y > pt.fin.y) // rajouter diff plus grand 1
	{
		if (pt.init.x <= *(int*)p[3] && l1->color != WHITE)
			p[4] = (void *)&l1->color;
		else if (pt.init.x > *(int*)p[3] && l1->next->color != WHITE)
			p[4] = (void *)&l1->next->color;
		else
			p[4] = NULL;
	}
	else if (pt.init.x == pt.fin.x)
	{
		if (pt.init.y <= *(int*)p[3] && l1->next->color != WHITE)
			p[4] = (void *)&l1->next->color;
		else if (pt.init.y > *(int*)p[3] && l2->color != WHITE)
			p[4] = (void *)&l2->color;
		else
			p[4] = NULL;
	}
	else if (pt.init.y < pt.fin.y) // rajouter diff plus grand 1
	{
		if (pt.init.x <= *(int*)p[3] && l1->next->color != WHITE)
			p[4] = (void *)&l1->next->color;
		else if (pt.init.x > *(int*)p[3] && l2->next->color != WHITE)
			p[4] = (void *)&l2->next->color;
		else
			p[4] = NULL;
	}
	if (p[4] != NULL)
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, *(int *)p[4]);
	else
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, WHITE);
}

void	rest_pixel(t_2pos *p, void **param, int *i)
{

}

t_pos	line(void **param, t_2pos p, t_line *l1, t_line *l2)
{
	int div;
	int i;
	int p_color;

	param[3] = (void *)&p_color;
	init(&p, &div, &p_color);
	while (p.init.y != p.fin.y)
	{
		i = 0;
		while (i < div && (p.init.x <= p.fin.x || p.init.x > p.fin.x))
		{
			pixel_color(p, l1, l2, param);
			if (p.init.x <= p.fin.x)
				p.init.x++;
			else
			p.init.x--;
			i++;
		}
		if (div == 0) // ligne droite y colorée
			pixel_color(p, l1, l2, param);
		if (p.init.y < p.fin.y)
			p.init.y++;
		if (p.init.y > p.fin.y)
			p.init.y--;
	}
	return (p.init);
}

t_2pos	square(void **param, t_pos init, t_line *l1, t_line *l2)
{
	static int i;
	t_2pos move;
	t_pos lgt;
	t_2pos p;

	p.init = init;
	if (!i)
		i = 0;
	lgt.x = 12 * 1; // (1 dans **param length)
	lgt.y = 5 * 1;
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y - lgt.y;
	p.init = line(param, p, l1, l2);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y + lgt.y;
	line(param, p, l1, l2);
	move.init = p.init;
	p.fin.x = p.init.x;
	p.fin.y = p.init.y + (lgt.y * 2);
	p.init = line(param, p, l1, l2);
	i++;
	if (i == 1)
		move.fin = p.init;
	if (l1->next->next == NULL)
		i = 0;
	return (move);
}
