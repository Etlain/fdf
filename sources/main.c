/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/31 03:46:47 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <fcntl.h>
#include <stdio.h>

int	val_key(int keycode, void *param)
{
	ft_putstr("\nkeycode :");
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	window()
{
}

int	main(int argc, char **argv)
{
	void	**param;
	/*t_pos	max;*/
	int 	fd;
	t_map	*map;
	t_pos init;
	/*int b_color;*/

	if (argc != 2)
	{
		ft_putstr("error : number of parameter\n");
		return (-1);
	}
	param = (void **)malloc(sizeof(void *) * 6);
	//param[3] = (void *)&b_color;
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd/*, &max, (int *)param[3]*/);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 800, 800, "fenetre");
	init.x = 200;
	init.y = 200;
	win_map(param, map, init);
	mlx_key_hook(param[1], val_key, 0);
	mlx_loop(param[0]);
	return (0);
}
