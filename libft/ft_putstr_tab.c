/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 21:11:19 by mmouhssi          #+#    #+#             */
/*   Updated: 2015/12/23 21:18:01 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		ft_putstr(tab[i]);
		i++;
	}
}