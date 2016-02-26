/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/02/26 15:25:36 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <fcntl.h>
int	ft(int keycode, void *param)
{
	ft_putchar('\n');
	ft_putnbr(keycode);
	return (0);
}

void	line_pos(void **param, t_pos init, t_pos fin, int color)
{
	int div_x;
	int i;
	int rest;
	int nbr;

	nbr = (((fin.x - init.x ) + 1) * 10) / ((fin.y - init.y) + 1);
	nbr = nbr - (nbr / 10) * 10;
	rest = 0;
	div_x = ((fin.x - init.x) + 1) / ((fin.y - init.y) + 1);
	while (init.y <= fin.y)
	{
		i = 0;
		while (i < div_x && init.x != fin.x + 1)
		{
			mlx_pixel_put(param[0], param[1], init.x, init.y, color);
			init.x++;
			i++;
			if (rest >= 10 && init.x < fin.x + 1)
			{
				mlx_pixel_put(param[0], param[1], init.x, init.y, color);
				init.x++;
				rest = rest - 10;
			}
		}
		rest = rest + nbr;
		init.y++;
		/*if (init.y < fin.y)
		{
			init.x--;
			mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
			init.x++;
		}*/
	}
}

void	line_neg(void **param, t_pos init, t_pos fin, int color)
{
	int div_x;
	int i;
	int rest;
	int nbr;

	nbr = (((init.x - fin.x ) + 1) * 10) / ((fin.y - init.y) + 1);
	nbr = nbr - (nbr / 10) * 10;
	rest = 0;
	div_x = ((init.x - fin.x) + 1) / ((fin.y - init.y) + 1);
	while (init.y <= fin.y)
	{
		i = 0;
		while (i < div_x && fin.x - 1 != init.x)
		{
			mlx_pixel_put(param[0], param[1], init.x, init.y, color);
			init.x--;
			i++;
			if (rest >= 10 && fin.x - 1 < init.x)
			{
				mlx_pixel_put(param[0], param[1], init.x, init.y, color);
				init.x--;
				rest = rest - 10;
			}
		}
		rest = rest + nbr;
		init.y++;
		/*if (init.y < fin.y)
		{
			init.x++;
			mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
			init.x--;
		}*/
	}
}

void	line_x(void **param, t_pos init, t_pos fin, int color)
{
	if (init.x <= fin.x)
		line_pos(param, init, fin, color);
	else
		line_neg(param, init, fin, color);
}

t_pos	ft_square(void **param, t_pos p, int length, int color)
{
	t_pos init;
	t_pos fin;
	t_pos lgt;

	lgt.x = 12 * length;
	lgt.y = 5 * length;
	fin.x = p.x - lgt.x;
	fin.y = p.y + lgt.y;
	line_x(param, p, fin, color);
	fin.x = p.x + lgt.x;
	fin.y = p.y + lgt.y;
	line_x(param, p, fin, color);
	return (lgt);
}
/*
int	main()
{
	void	**param;
	t_pos	max;
	int 	fd;
	t_map	*map;
	t_pos init;
	t_pos lgt;

	param = (void **)malloc(sizeof(void *) * 2);
	fd = open("map.fdf", O_RDONLY);
	map = read_map(fd, &max);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 300, 300, "fenetre");
	init.x = 100;
	init.y = 100;
	lgt = ft_square(param, init, 1);
	init.x = init.x + lgt.x;
	init.y = init.y - lgt.y - 1;
	lgt = ft_square(param, init, 1);
	init.x = init.x + lgt.x;
	init.y = init.y - lgt.y - 1;
	lgt = ft_square(param, init, 1);
	mlx_loop(param[0]);
	return (0);
}
*/
/*
void	ft_line(void **param, t_pos init, t_pos fin)
{
	int div_x;
	int i;
	int rest;
	int nbr;

	nbr = (((fin.x - init.x ) + 1) * 10) / ((fin.y - init.y) + 1);
	nbr = nbr - (nbr / 10) * 10;
	rest = 0;
	div_x = ((fin.x - init.x) + 1) / ((fin.y - init.y) + 1);
	while (init.y <= fin.y)
	{
		i = 0;
		while (i < div_x && init.x != fin.x + 1)
		{
			mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
			//ft_putstr("\nx : ");
			//ft_putnbr(init.x);
			init.x++;
			i++;
			if (rest >= 10 && init.x < fin.x + 1)
			{
				mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
				//ft_putstr("\nx : ");
				//ft_putnbr(init.x);
				init.x++;
				rest = rest - 10;
			}
		}
		rest = rest + nbr;
		init.y++;
		//ft_putstr("\n\ny : ");
		//ft_putnbr(init.y);
		if (init.y < fin.y)
		{
			init.x--;
			//ft_putstr("\nx : ");
			//ft_putnbr(init.x);
			mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
			init.x++;
		}
	}
}*/

/*
void	line_y(void **param, t_pos init, t_pos fin)
{
	int div_y;
	int i;
	int rest;
	int nbr;

	div_y = ((fin.y - init.y) + 1) / ((fin.x - init.x) + 1);
	while (init.x <= fin.x)
	{
		i = 0;
		while (i < div_y && init.y != fin.y + 1)
		{
			mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
			init.y++;
			i++;
		}
		rest = rest + nbr;
		init.x++;
		if (init.x < fin.x)
		{
			init.y--;
			mlx_pixel_put(param[0], param[1], init.x, init.y, 0xFFFFFF);
			init.y++;
		}
	}
}*/
