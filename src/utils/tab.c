/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:15:23 by afavre            #+#    #+#             */
/*   Updated: 2023/08/25 13:42:21 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_int_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}
}

void	print_map(t_data *data)
{
	int h;
	int l;

	h = 0;
	while (h < data->map.h_map)
	{
		l = 0;
		while (l < data->map.l_map)
		{
			printf("%c", data->map.map[h][l]);
			l++;
		}
		printf("\n");
		h++;
	}
}

void	print_char_tab(char **tab)
{
	int h;
	int l;

	h = 0;
	while (tab[h])
	{
		l = 0;
		while (tab[h][l])
		{
			printf("%c", tab[h][l]);
			l++;
		}
		h++;
	}
}