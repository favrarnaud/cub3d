/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:43:39 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 14:27:50 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	verify_map(t_data *data)
{
	int dup;

	dup = 0;
	if (check_char_dup(data->map.map, &dup) == false)
		return (false);
	if (check_closed_map(data) == false)
		return (false);
	
	return (true);
	
}

void	fill_tab_x(char **map, int tab_len, int len)
{
	int	i;
	int j;

	i = 0;
	while(i < tab_len + 2)
	{
		map[i] = pro_malloc((len + 3) * (sizeof(char)));
		j = 0;
		while(j < len + 2)
		{
			map[i][j] = 'x';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

void	fill_map(char **map, char **tab_tmp, int h_len)
{
	int	l;
	int h;

	h = 1;
	while (h < h_len - 1)
	{
		l = 1;
		while (map[h][l] && tab_tmp[h-1][l-1])
		{
			if (tab_tmp[h-1][l-1] != 'x' && tab_tmp[h-1][l-1] != ' ')
				map[h][l] = tab_tmp[h-1][l-1];
			l++;
		}
		h++;
	}
}

int	longest_str(char **tab_tmp)
{
	int i;
	size_t max_len;

	i = 0;
	max_len = ft_strlen(tab_tmp[i]);
	while (tab_tmp[i])
	{
		if (ft_strlen(tab_tmp[i+1]) >= max_len)
			max_len = ft_strlen(tab_tmp[i+1]);
		i++; 
	}
	return (max_len);
}

bool	check_map(t_data *data, int fd)
{
	char	*tmp;
	char	*tmp2;
	char	**tab_tmp;
	char	*str;
	
	tmp = NULL;
	str = get_next_line(fd);
	while (str && !empty_line(str))
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, str);
		free(tmp2);
		free(str);
		str = get_next_line(fd);
	}
	tab_tmp = ft_split(tmp, '\n');
	data->map.h_map = tab_size(tab_tmp) + 2;
	data->map.l_map = longest_str(tab_tmp) + 2;
	data->map.map = pro_malloc((data->map.h_map + 1) * (sizeof(char *)));
	fill_tab_x(data->map.map, data->map.h_map - 2, data->map.l_map - 2);
	fill_map(data->map.map, tab_tmp, data->map.h_map);
	print_map(data);
	return (verify_map(data));
	// then check map values (no hole in walls, only one N/S/E/O and only 1 or 0)
}
