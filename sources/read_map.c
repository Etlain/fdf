/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:44:20 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/03/03 13:50:25 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_line  *add_lst_line(t_line *line, char *tab)
{
	char **buf;
	t_line *end;
	t_line *tmp;

	buf = ft_strsplit(tab, ',');
	tmp = (t_line *)malloc(sizeof(t_line));
	tmp->height = ft_atoi(buf[0]);
	if (buf[1] != NULL)
		tmp->color = ft_htoi(buf[1]);
	else
		tmp->color = 0xFFFFFF;
	tmp->next = NULL;
	if (line)
	{
		end = line;
		while (end->next != NULL)
			end = end->next;
	}
	else
		return (tmp);
	end->next = tmp;
	ft_free_tab(buf);
	return (line);
}

static t_map	*add_lst_map(t_map *map, char **tab, int x)
{
	t_map *tmp;
	t_map *end;
	int i;

	tmp = (t_map*)malloc(sizeof(t_map));
	tmp->line = NULL;
	i = 0;
	while (tab[i] != NULL)
	{
		tmp->line = add_lst_line(tmp->line, tab[i]);
		i++;
		//if (pos->x < i)
	}
	x < i ? x = i : 0;
	tmp->next = NULL;
	if (map)
	{
		end = map;
		while (end->next != NULL)
			end = end->next;
	}
	else
		return (tmp);
	end->next = tmp;
	return (map);
}

void	put_lst(t_map *map) // a effacer a la fin
{
	t_map *tmp;
	t_line *line;

	tmp = map;
	while (tmp != NULL)
	{
		line = tmp->line;
		while (line != NULL)
		{
			ft_putnbr(line->height);
			ft_putchar(',');
			ft_putnbr(line->color);
			ft_putchar(' ');
			line = line->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

t_map	*read_map(int fd, t_pos *pos)
{
	t_map *map;
	char *line;
	char **tab;

	map = NULL;
	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->y = 0;
	pos->x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		map = add_lst_map(map, tab, pos->x);
		free(tab);
		(pos)->y++;
	}
	return (map);
}
