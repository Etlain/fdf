/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/13 15:54:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_div(t_2pos *p, t_div *div, int *b_rest, int *p_color)
{
	int p_y;

	p_y = (p->fin.y - p->init.y) + 1;
	if (p->fin.x >= p->init.x)
	{
		div->rest = (((p->fin.x - p->init.x ) + 1) * 10) / p_y;
		div->res = ((p->fin.x - p->init.x) + 1) / p_y;
		*p_color = p->fin.x - (p->fin.x - p->init.x) / 2;
		if (p->fin.x == p->init.x)
			*p_color = p->fin.y - (p->fin.y - p->init.y) / 2;
	}
	else
	{
		div->rest = (((p->init.x - p->fin.x) + 1) * 10) / p_y;
		div->res = ((p->init.x - p->fin.x) + 1) / p_y;
		*p_color = p->init.x - (p->init.x - p->fin.x) / 2;
	}
	div->rest = div->rest - (div->rest / 10) * 10;
	*b_rest = 0;
}

void	pixel_color(t_2pos pt, t_line *l1, t_line *l2, void **p)
{
	ft_putstr("\npixel color : ");
	if (pt.init.x < pt.fin.x) // rajouter diff plus grand 1
	{
		if (pt.init.x <= *(int*)p[3] && l1->next->color != WHITE)
			p[4] = (void *)&l1->next->color;
		else if (pt.init.x > *(int*)p[3] && l2->next->color != WHITE)
			p[4] = (void *)&l2->next->color;
		else
			p[4] = NULL;
		ft_putstr("pb :");
		ft_putnbr(l2->next->color);
	}
	else if (pt.init.x > pt.fin.x) // rajouter diff plus grand 1
	{
		if (pt.init.x >= *(int*)p[3] && l1->next->color != WHITE)
			p[4] = (void *)&l1->next->color;
		else if (pt.init.x < *(int*)p[3] && l1->color != WHITE)
			p[4] = (void *)&l1->color;
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
	if (p[4] != NULL)
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, *(int *)p[4]);
	else
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, WHITE);
}

void	rest_pixel(t_2pos *p, void **param, int *b_rest, int *i)
{
	int color;

	color = WHITE;
	if (p->init.x <= p->fin.x)
		p->init.x++;
	else
		p->init.x--;
	if (*b_rest >= 10 && p->init.x < p->fin.x + 1)
	{
		color = *(int *)param[4];
		if (param[4] == NULL)
			color = WHITE;
		mlx_pixel_put(param[0], param[1], p->init.x, p->init.y, color);
		if (p->init.x <= p->fin.x)
			p->init.x++;
		else
			p->init.x--;
		*b_rest = *b_rest - 10;
	}
	(*i)++;
}

void	line(void **param, t_2pos p, t_line *l1, t_line *l2)
{
	t_div div;
	int i;
	int b_rest;
	int p_color;

	param[3] = (void *)&p_color;
	init_div(&p, &div, &b_rest, &p_color);
	while (p.init.y <= p.fin.y)
	{
		i = 0;
		while (i < div.res && (p.init.x <= p.fin.x || p.init.x > p.fin.x))
		{
			pixel_color(p, l1, l2, param);
			rest_pixel(&p, param, &b_rest, &i);
		}
		if (div.res == 0)
			pixel_color(p, l1, l2, param);
		b_rest = b_rest + div.rest;
		p.init.y++;
	}
}

t_pos	square(void **param, t_2pos p, t_line *l1, t_line *l2)
{
	t_pos lgt;

	lgt.x = 12 * 1; // (1 dans **param length)
	lgt.y = 5 * 1;
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y + lgt.y;
	ft_putstr("\ncarre :");
	line(param, p, l1, l2);
	p.fin.x = p.init.x - lgt.x;
	p.fin.y = p.init.y + lgt.y;
	line(param, p, l1, l2);
	p.fin.x = p.init.x;
	p.fin.y = p.init.y + (lgt.y * 2);
	line(param, p, l1, l2);
	return (lgt);
}
