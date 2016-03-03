/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:33:01 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/03 13:28:57 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

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

t_map			*read_map(int fd, t_pos *pos);
t_pos			square(void **param, t_pos pos, t_line *line);
void			win_map(void **param, t_map *map, t_pos init);

#endif
