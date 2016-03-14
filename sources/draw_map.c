/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/14 15:11:35 by mmouhssi         ###   ########.fr       */
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

void	win_map(void **p, t_map *map, t_pos init)
{
	t_map *tmp;
	t_line *l_next;
	t_2pos s;
	t_pos lgt;
	int i;

	s.init.x = init.x;
	s.init.y = init.y;
	tmp = map;
	i = 1;
	while (tmp->next != NULL)
	{
		l_next = tmp->next->line;
		while (tmp->line->next != NULL)
		{
			s = square(p, init, tmp->line, l_next);
			l_next = l_next->next;
			tmp->line = tmp->line->next;
			init = s.init;
			//s.init.x = s.init.x + lgt.x;
			//s.init.y = s.init.y - lgt.y - 1;
			//break ;
		}
		init = s.fin;
		//s.init.x = init.x + lgt.x * i;
		//s.init.y = init.y + (lgt.y + 1) * i;
		//i++;
		tmp = tmp->next;
		//break ;
	}
}
