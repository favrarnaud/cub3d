/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:32:43 by afavre            #+#    #+#             */
/*   Updated: 2023/08/09 12:32:45 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_data *data)
{
	int		color_sky;
	int		color_floor;
	t_point	t;
	t_rect	rect;

	t.x = 0;
	t.y = 0;
	rect.height = data->mlx.screen_height / 2;
	rect.width = data->mlx.screen_width;
	color_sky = new_color(50, 210, 243, 0);
	color_floor = new_color(247, 230, 187, 0);
	render_rect(data, t, rect, color_sky);
	t.y = data->mlx.screen_height / 2;
	render_rect(data, t, rect, color_floor);
}

void	update_img(t_data *data)
{
	draw_background(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, \
	data->img.mlx_img, 0, 0);
}
