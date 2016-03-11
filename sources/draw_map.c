/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/11 01:29:14 by mmouhssi         ###   ########.fr       */
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
		while (tmp->line->next != NULL)
		{
			lgt = square(p, s, tmp->line, tmp->next->line->next);
			tmp->line = tmp->line->next;
			s.init.x = s.init.x + lgt.x;
			s.init.y = s.init.y - lgt.y - 1;
			//break ;
		}
		s.init.x = init.x + lgt.x * i;
		s.init.y = init.y + (lgt.y + 1) * i;
		i++;
		tmp = tmp->next;
		//break ;
	}
}
