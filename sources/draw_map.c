/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/02/26 14:59:21 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <fcntl.h>
/*int	ft(int keycode, void *param)
{
	ft_putchar('\n');
	ft_putnbr(keycode);
	return (0);
}*/
/*
void	win_line(void **param, t_line *line, t_pos *pos, int length)
{
	int x;
	int y;
	int gap;
	int i;

	y = pos->y;
	gap = 0;
	i = 0;
	while (y < pos->y + length / 2)
	{
		x = pos->x + gap;
		if (x < 0)
			exit(-1);
		while (x < pos->x + (length / 2) + gap + i)
		{
			//if (gap == 0 || x == pos->x + gap + (length / 2) + i - 1)
				mlx_pixel_put(param[0], param[1], x, y, line->color);
			x++;
			//ft_putnbr(x);
			//ft_putchar('\n');
			if (x % 2 != 0)
				y--;
		}
		//ft_putnbr(y);
		//ft_putchar('\n');
		gap++;
		if (y % 2 == 0)
			i++;
		y = pos->y + gap;
	}
}

void	win_map(void **param, t_map *map)
{
	t_map *tmp;
	t_pos *pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->x = 150;
	pos->y = 150;
	tmp = map;
	while (tmp != NULL)
	{
		while (tmp->line != NULL)
		{
			win_line(param, tmp->line, pos, 24);
			tmp->line = tmp->line->next;
			pos->x = pos->x + 12;
			pos->y = pos->y - 6;
			break ;
		}
		pos->x = pos->x - 60;
		pos->y = pos->y + 12;
		tmp = tmp->next;
		break ;
	}
}
*//*
void	win_line(void **param, int color, t_pos *pos, int length)
{
	
}
*/
void	win_map(void **param, t_map *map, t_pos init)
{
	t_map *tmp;
	t_pos pos;
	t_pos lgt;
	int i;

	pos.x = init.x;
	pos.y = init.y;
	tmp = map;
	i = 1;
	while (tmp != NULL)
	{
		while (tmp->line != NULL)
		{
			lgt = ft_square(param, pos, 1);
			tmp->line = tmp->line->next;
			pos.x = pos.x + lgt.x;
			pos.y = pos.y - lgt.y - 1;
			//break ;
		}
		pos.x = init.x + lgt.x * i;
		pos.y = init.y + (lgt.y + 1) * i;
		i++;
		tmp = tmp->next;
		//break ;
	}
}
