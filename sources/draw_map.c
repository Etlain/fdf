/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/30 23:18:24 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
/*int	ft(int keycode, void *param)
{
	ft_putchar('\n');
	ft_putnbr(keycode);
	return (0);
}*/

t_pos	square(void **param, t_pos init, t_line *l1, t_line *l2)
{
	static int i;
	t_2pos move;
	t_pos lgt;
	t_pos tmp;
	t_2pos p;
	int height;

	p.init = init;
	if (!i)
		i = 0;
	//ft_putnbr(l1->height);
	// Here
	if (l1->height >= l1->next->height)
		height = l1->next->height - l1->height;
	else
		height = l1->next->height - l1->height;
	lgt.x = 11 * 1; // (1 dans **param length p[2])
	lgt.y = 5 * 1 * (height + 1);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y - lgt.y;
	line(param, p, l1, l2);
	mlx_pixel_put(param[0], param[1], p.init.x, p.init.y, 0xFF0000);
	mlx_pixel_put(param[0], param[1], p.fin.x, p.fin.y, 0xFF0000);
	p.init.x = p.fin.x;
	p.init.y = p.fin.y;
	//lgt.x = 11 * 3; // (1 dans **param length p[2])
	if (l1->next->height > l2->next->height)
		height = l1->next->height - l2->next->height;
	else
		height = l1->next->height - l2->next->height;
	lgt.y = 5 * 1 * (height + 1);
	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y + lgt.y;
	line(param, p, l1, l2);
	mlx_pixel_put(param[0], param[1], p.init.x, p.init.y, 0xFF0000);
	mlx_pixel_put(param[0], param[1], p.fin.x, p.fin.y, 0xFF0000);
	/*move.init = tmp;*/
	/*lgt.x = 12 * 5; // (1 dans **param length p[2])
	lgt.y = 5 * 5 * (l1->height + 1);
	p.fin.x = p.init.x - lgt.x;
	p.fin.y = p.init.y + lgt.y;
	p.fin = line(param, p, l1, l2);*/
	// STOP
// ok
/*	p.fin.x = p.init.x + lgt.x;
	p.fin.y = p.init.y - (lgt.y * 10);
	line(param, p, l1, l2);*/
/*	p.fin.x = p.init.x + (lgt.x);
	p.fin.y = p.init.y + (lgt.y * 10);
	line(param, p, l1, l2);*/
//
/*	move.init = p.init;
	lgt.x = 12 * 5; // (1 dans **param length p[2])
	lgt.y = abs(p.init.y - p.fin.y);
*/	
/*	pareil
	p.init = tmp;
	p.fin.x = p.init.x - lgt.x;
	p.fin.y = p.init.y + (lgt.y);
	line(param, p, l1, l2);*/
/*	p.init.x = p.fin.x;
	p.fin.y = p.init.y - 100;
	line(param, p, l1, l2);*/

	/*//ATTENTION DANGER
	p.init.x = 100;
	p.init.y = 400;
	p.fin.x = 699;
	p.fin.y = 381;
	tmp = line(param, p, l1, l2);
	mlx_pixel_put(param[0], param[1], p.init.x, p.init.y, 0xFF0000);
	mlx_pixel_put(param[0], param[1], p.fin.x, p.fin.y, 0xFF0000);
	ft_putnbr(tmp.x);
	ft_putchar(' ');
	ft_putnbr(tmp.y);*/
	//----------------
	i++;
	if (i == 1)
		move.fin = p.init;
	if (l1->next->next == NULL)
		i = 0;
	return (p.init);
}

void	win_map(void **p, t_map *map, t_pos init)
{
	t_map *tmp;
	t_line *l_next;
	t_2pos s;
	t_pos lgt;
	int i;

	tmp = map;
	//i = 1;
	while (tmp->next != NULL)
	{
		s.init = init;
		l_next = tmp->next->line;
		i = 0;
		while (tmp->line->next != NULL)
		{
			printf("init.y : %d\n", init.y);
			s.init = square(p, s.init, tmp->line, l_next);
			l_next = l_next->next;
			tmp->line = tmp->line->next;
			//init = s.init;
			/*s.init.x = s.init.x + lgt.x;
			s.init.y = s.init.y - lgt.y;*/
			//init = s.init;
			i++;
			//break ;
		}
		//init = s.fin;
		//i++;
		//printf("s.init.y : %d\n", s.init.y);
		init.x = s.init.x - 11 * 1 * (i - 1);
		init.y = s.init.y + 5 * 1 * (i + 1) + 5 * 1 * (tmp->line->height);
		//printf("init.y : %d\n", init.y);
		/*init.x = init.x + 11 * 1;
		init.y = init.y + 5 * 1 * (tmp->line->height + l_next->height + 1);*/
		tmp = tmp->next;
		init.y = init.y - 5 * 1 * (tmp->line->height);
		//break ;
	}
}

/*
void	win_map(void **p, t_map *map, t_pos init)
{
	t_map *tmp;
	t_line *l_next;
	t_2pos s;
	t_pos lgt;
	int i;

	tmp = map;
	//i = 1;
	while (tmp->next != NULL)
	{
		s.init.x = init.x;
		s.init.y = init.y;
		l_next = tmp->next->line;
		i = 0;
		while (tmp->line->next != NULL)
		{
			lgt = square(p, s.init, tmp->line, l_next);
			l_next = l_next->next;
			tmp->line = tmp->line->next;
			//init = s.init;
			s.init.x = s.init.x + lgt.x;
			s.init.y = s.init.y - lgt.y;
			//init = s.init;
			i++;
			//break ;
		}
		//init = s.fin;
		init.x = init.x + lgt.x;
		init.y = init.y + (lgt.y);
		//i++;
		tmp = tmp->next;
		//break ;
	}
}*/
