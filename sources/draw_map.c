/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/02/26 15:26:05 by mmouhssi         ###   ########.fr       */
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
			lgt = ft_square(param, pos, 1, tmp->line->color);
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
