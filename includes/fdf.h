/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:33:01 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/09 22:19:26 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# define WHITE 0xFFFFFF

typedef struct		s_line
{
	int		height;
	int		color;
	struct s_line	*next;
}			t_line;

typedef struct		s_map
{
	t_line		*line;
	int		length;
	int		b_color;
	struct s_map	*next;
}			t_map;

typedef struct		s_2pos
{
	t_pos		init;
	t_pos		fin;
}			t_2pos;

typedef struct		s_div
{
	int		res;
	int		rest;
}			t_div;

t_map			*read_map(int fd, t_pos *pos);
t_pos			square(void **param, t_2pos p, t_line *l1, t_line *l2);
void			win_map(void **param, t_map *map, t_pos init);

#endif
