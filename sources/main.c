/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/14 15:29:18 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <fcntl.h>
int	main(int argc, char **argv)
{
	void	**param;
	t_pos	max;
	int 	fd;
	t_map	*map;
	t_pos init;
	t_pos lgt;

	if (argc != 2)
	{
		ft_putstr("error : number of parameter\n");
		return (-1);
	}
	param = (void **)malloc(sizeof(void *) * 5);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd, &max);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 300, 300, "fenetre");
	init.x = 50;
	init.y = 200;
	win_map(param, map, init);
	mlx_loop(param[0]);
	return (0);
}
