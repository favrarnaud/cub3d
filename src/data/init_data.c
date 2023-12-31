/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:12:27 by afavre            #+#    #+#             */
/*   Updated: 2023/09/22 14:27:47 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->texture.no_dup.north = 0;
	data->texture.no_dup.south = 0;
	data->texture.no_dup.east = 0;
	data->texture.no_dup.west = 0;
	data->texture.no_dup.floor = 0;
	data->texture.no_dup.ceilling = 0;
	data->cam.dir_x = 1;
	data->cam.dir_y = 0;
	data->cam.plane_x = 0;
	data->cam.plane_y = 0.66;
	data->cam.r_sp = 0.05;
	data->cam.m_sp = 0.1;
}
