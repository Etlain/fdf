/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/31 02:34:12 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_2pos *p, double *div, int *p_color, int *b_x)
{
	int p_y;
	int p_x;

	p_y = ft_abs(p->fin.y - p->init.y) + 1;
	p_x = ft_abs(p->fin.x - p->init.x) + 1;
	*b_x = 0;
	if (p_x < p_y)
		*b_x = 1;
	*div = (double)p_x / (double)p_y;
	if (p->init.y <= p->fin.y)
		p->fin.y++;
	else
		p->fin.y--;
	if (p->init.x <= p->fin.x)
		p->fin.x++;
	else
		p->fin.x--;
	if (p->fin.x > p->init.x)
		*p_color = p->fin.x;
	else if (p->fin.x < p->init.x)
		*p_color = p->init.x;
	if (p->init.x != p->fin.x)
		*p_color = *p_color - (p->fin.x - p->init.x) / 2;
	else
		*p_color = p->fin.y - (p->fin.y - p->init.y) / 2;
	//printf("%f = %d / %d\n", *div, p_x, p_y);
}

void	color(void **p , int x, int *color, int *color2)
{
	if (x <= *(int*)p[4] && *color != WHITE)
			p[5] = (void *)color;
		else if (x > *(int*)p[4] && *color2 != WHITE)
			p[5] = (void *)color2;
		else
			p[5] = NULL;
}

void	pixel_color(t_2pos pt, t_line *l1, t_line *l2, void **p)
{
	/*int b_x;

	b_x = 0;
	if (abs(pt.fin.x - pt.init.x) < abs(pt.fin.y - pt.init.y))
		b_x = 1;*/
	if (pt.init.y > pt.fin.y/* && b_x == 0*/)
		color(p, pt.init.x, &l1->color, &l1->next->color);
	else if (pt.init.x == pt.fin.x)
		color(p, pt.init.y, &l1->next->color, &l2->color);
	else if (pt.init.y < pt.fin.y/* && b_x == 0*/)
		color(p, pt.init.x, &l1->next->color, &l2->next->color);
/*	else if (pt.init.y > pt.fin.y)
		color(p, pt.init.x, &l1->next->color, &l1->color);*/
	/*else if (pt.init.y < pt.fin.y)
		color(p, pt.init.x, &l2->next->color, &l1->next->color);*/
	if (pt.init.x == pt.fin.x && *(int *)p[3] == 0)
		return ;
	if (p[5] != NULL) // ajouter condition couleur
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, *(int *)p[5]);
	else
		mlx_pixel_put(p[0], p[1], pt.init.x, pt.init.y, WHITE);
}

int	add_rest(double div)
{
	static double rest;
	int nbr_x;
	
	nbr_x = div;
	if (div == 0)
	{
		rest = 0;
		return (0);
	}
	if (!rest)
		rest = div - nbr_x;
	else if (rest <= 1)
		rest = rest + (div - nbr_x);
	if (rest > 1)
	{
		nbr_x++;
		rest = rest - 1;
	}
	return (nbr_x);
}

void	line(void **param, t_2pos p, t_line *l1, t_line *l2)
{
	double div;
	int i;
	int p_color;
	int b_x; // 1 ligne eventuel

	param[4] = (void *)&p_color; // pk pas
	init(&p, &div, &p_color, &b_x);
	while (p.init.y != p.fin.y)
	{
		if (b_x == 1)
		{
			if (add_rest(div) == 1 && p.init.x != p.fin.x)
				p.init.x < p.fin.x ? p.init.x++ : p.init.x--;
			pixel_color(p, l1, l2, param);
		}
		else
		{
			i = 0;
			while (i < add_rest(div))
			{
				pixel_color(p, l1, l2, param);
				if (b_x == 0 && p.init.x != p.fin.x)              // 3 ligne
					p.init.x < p.fin.x ? p.init.x++ : p.init.x--;
				i++;
			}
		}
		p.init.y < p.fin.y ? p.init.y++ : p.init.y--;
	}
	add_rest(0);
}
