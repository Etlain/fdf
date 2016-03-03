/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/03 14:12:22 by mmouhssi         ###   ########.fr       */
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
	param = (void **)malloc(sizeof(void *) * 2);
	fd = open(argv[1], O_RDONLY);
	//fd = open("example/maps/test", O_RDONLY);
	map = read_map(fd, &max);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 300, 300, "fenetre");
	init.x = 100;
	init.y = 100;
	win_map(param, map, init);
	/*lgt = ft_square(param, init, 1);
	init.x = init.x + lgt.x;
	init.y = init.y - lgt.y - 1;
	lgt = ft_square(param, init, 1);
	init.x = init.x + lgt.x;
	init.y = init.y - lgt.y - 1;
	lgt = ft_square(param, init, 1);
	*/mlx_loop(param[0]);
	return (0);
}
