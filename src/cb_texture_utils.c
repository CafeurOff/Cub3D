/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:40:05 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:27:55 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

uint32_t	ft_ea_color(t_game *game)
{
	uint32_t	color;

	color = 0;
	if (game->ray->ray_a < 3 * M_PI_2 && game->ray->ray_a > M_PI_2)
		color = (int)(game->texture->wall_we->pixels[game->dl->pixel]) << 24
			| (int)(game->texture->wall_we->pixels[game->dl->pixel + 1]) << 16
			| (int)(game->texture->wall_we->pixels[game->dl->pixel + 2]) << 8
			| (int)(game->texture->wall_we->pixels[game->dl->pixel + 3]);
	else
		color = (int)(game->texture->wall_ea->pixels[game->dl->pixel]) << 24
			| (int)(game->texture->wall_ea->pixels[game->dl->pixel + 1]) << 16
			| (int)(game->texture->wall_ea->pixels[game->dl->pixel + 2]) << 8
			| (int)(game->texture->wall_ea->pixels[game->dl->pixel + 3]);
	return (color);
}


uint32_t	ft_no_color(t_game *game)
{
	uint32_t	color;

	color = 0;
	if (game->ray->ray_a < M_PI && game->ray->ray_a > 0)
		color = (int)(game->texture->wall_so->pixels[game->dl->pixel]) << 24
			| (int)(game->texture->wall_so->pixels[game->dl->pixel + 1]) << 16
			| (int)(game->texture->wall_so->pixels[game->dl->pixel + 2]) << 8
			| (int)(game->texture->wall_so->pixels[game->dl->pixel + 3]);
	else
		color = (int)(game->texture->wall_no->pixels[game->dl->pixel]) << 24
			| (int)(game->texture->wall_no->pixels[game->dl->pixel + 1]) << 16
			| (int)(game->texture->wall_no->pixels[game->dl->pixel + 2]) << 8
			| (int)(game->texture->wall_no->pixels[game->dl->pixel + 3]);
	return (color);
}
