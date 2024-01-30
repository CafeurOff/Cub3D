/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:40:05 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/30 00:18:08 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	ft_rgb_hex(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	ft_set_pixel(mlx_image_t *img, int max_x, int max_y, u_int32_t c)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
	{
		y = 0;
		while (y < max_y)
		{
			mlx_put_pixel(img, x, y, c);
			y++;
		}
		x++;
	}
}

