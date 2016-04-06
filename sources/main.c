/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/06 17:40:32 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	void	**param;
	int 	fd;

	if (argc != 2)
	{
		ft_put_error("error : number of parameter");
		return (-1);
	}
	param = (void **)malloc(sizeof(void *) * 6);
	param[6] = NULL;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_put_error("error : open file");
		return (-1);
	}
	map = read_map(fd);
	close(fd);
	draw_fdf(map, param);
	return (0);
}
