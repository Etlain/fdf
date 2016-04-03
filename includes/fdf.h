/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:33:01 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/03 15:40:55 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# define WHITE 0xFFFFFF
# define H 800
# define W 800
# define X  2 //11 2
# define Y  1 //5  1

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
	struct s_map	*next;
}			t_map;

typedef struct		s_2pos
{
	t_pos		init;
	t_pos		fin;
}			t_2pos;

typedef struct		s_env
{
	void		**p;
	t_map		*map;
	t_pos		*init;
	int		*zoom;
}			t_env;

t_map			*read_map(int fd);
void			line(void **param, t_2pos p, t_line *l1, t_line *l2);
void			win_map(void **p, t_map *map, t_pos init);
void			redraw(t_env *env);
void			draw_fdf(t_map *map, void **param);
int			expose_hook(t_env *env);
int			key_hook(int keycode, t_env *env);
void			pixel_c(t_2pos pt, t_line *l1, t_line *l2, void **p);
void			free_lst(t_map *map);
#endif
