/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/02 22:42:38 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init(t_2pos *p, double *div, int *p_color, int *b_x)
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
}

static int	rest(double div)
{
	static double	rest;
	int 		nbr_x;

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

static void	condition(t_2pos *p, int *i, int b_x)
{
	if (b_x == 0)
	{
		if (p->init.x != p->fin.x)
			p->init.x < p->fin.x ? p->init.x++ : p->init.x--;
		(*i)++;
	}
}

void		line(void **param, t_2pos p, t_line *l1, t_line *l2)
{
	double	div;
	int 	i;
	int 	b_x;
	int 	r_div;

	init(&p, &div, (int *)param[3], &b_x);
	while (p.init.y != p.fin.y)
	{
		r_div = rest(div);
		i = 0;
		if (b_x == 1)
		{
			if (r_div == 1 && p.init.x != p.fin.x)
				p.init.x < p.fin.x ? p.init.x++ : p.init.x--;
			pixel_c(p, l1, l2, param);
		}
		while (b_x == 0 && i < r_div)
		{
			pixel_c(p, l1, l2, param);
			condition(&p, &i, b_x);
		}
		p.init.y < p.fin.y ? p.init.y++ : p.init.y--;
	}
	rest(0);
}
