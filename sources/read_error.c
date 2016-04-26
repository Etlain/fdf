/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:44:20 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/26 21:56:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		error_nbval(int *x, int i)
{
	if (*x == 0)
		*x = i;
	else if (*x != i)
	{
		ft_put_error("error : number value in line");
		exit(-1);
	}
}

void		error_heigth(char *b)
{
	int i;

	i = 0;
	while (b[i] != '\0')
	{
		if ((b[i] < '0' || b[i] > '9') && b[i] != '-')
		{
			ft_put_error("error : heigth in file");
			exit(-1);
		}
		i++;
	}
}

void		error_color(char *b)
{
	int i;

	if (b[0] != '0' || (b[1] != 'x' && b[1] != 'X'))
	{
		ft_put_error("error : color in file 0x or 0X");
		exit(-1);
	}
	i = 2;
	while (b[i] != '\0')
	{
		if ((b[i] >= 'A' && b[i] <= 'F') || (b[i] >= 'a' && b[i] <= 'f'))
			i++;
		else if (b[i] >= '0' && b[i] <= '9')
			i++;
		else
		{
			ft_put_error("error : color in file val hexa");
			exit(-1);
		}
	}
}
