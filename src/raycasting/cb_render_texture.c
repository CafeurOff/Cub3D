/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:04:18 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 03:04:29 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int	ft_get_pixel(int x, int y, t_img *img)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

long	ft_get_colors(t_game *game)
{
	long	color;

	color = 0;
	if (game->ray->shade == 0.5)
		color = ft_get_we_ea_color(game);
	else
		color = ft_get_no_so_color(game);
	return (color);
}

long	ft_get_we_ea_color(t_game *game)
{
	long	color;

	if (game->ray->ray_a < 3 * M_PI_2 && game->ray->ray_a > M_PI_2)
		color = ft_get_pixel((int)game->dl->tx, (int)game->dl->ty,
				game->texture->wall_we);
	else
		color = ft_get_pixel((int)game->dl->tx, (int)game->dl->ty,
				game->texture->wall_ea);
	return (color);
}

long	ft_get_no_so_color(t_game *game)
{
	long	color;

	if (game->ray->ray_a < M_PI && game->ray->ray_a > 0)
		color = ft_get_pixel((int)game->dl->tx, (int)game->dl->ty,
				game->texture->wall_no);
	else
		color = ft_get_pixel((int)game->dl->tx, (int)game->dl->ty,
				game->texture->wall_so);
	return (color);
}
