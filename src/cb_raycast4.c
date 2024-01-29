/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:22:00 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:40:16 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_set_cos(t_game *game)
{
	game->cast->ca = game->cast->pa - game->ray->ray_a - game->drunk;
	if (game->cast->ca < 0)
		game->cast->ca += 2 * M_PI;
	if (game->cast->ca > 2 * M_PI)
		game->cast->ca -= 2 * M_PI;
	game->ray->final_d *= cos(game->cast->ca);
	game->cast->line_hight = 128 * game->dis_h / game->ray->final_d;
	game->ray->ty_step = 64.0 / (double)game->cast->line_hight;
	game->ray->ty_off = 0;
	if (game->cast->line_hight > game->dis_h)
	{
		game->ray->ty_off = (game->cast->line_hight - game->dis_h) / 2.0;
		game->cast->line_hight = game->dis_h;
	}
	game->cast->line_offset = (game->dis_h / 2) - game->cast->line_hight / 2;
	game->ray->final_d *= cos(game->cast->ca);
}

void	ft_set_render(t_game *game)
{
	game->dl->ty = game->ray->ty_off * game->ray->ty_step;
	game->dl->begin_x = game->ray->rays * (game->dis_w / game->ray->n_of_rays);
	if (game->ray->shade == 1)
	{
		game->dl->tx = (int)(game->ray->ray_x / 2.0) % 64;
		if (game->ray->ray_a < M_PI)
			game->dl->tx = 63 - game->dl->tx;
	}
	else
	{
		game->dl->tx = (int)(game->ray->ray_y / 2.0) % 64;
		if (game->ray->ray_a > M_PI_2 && game->ray->ray_a < (3 * M_PI_2))
			game->dl->tx = 63 - game->dl->tx;
	}
}

void	ft_draw_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->cast->line_hight)
	{
		game->dl->pixel = ((int)game->dl->ty * game->texture->wall_no->width
				+ (int)game->dl->tx)
			* game->texture->wall_no->bytes_per_pixel;
		game->dl->color = ft_wall_color(game);
		j = -1;
		while (++j < 4)
			mlx_put_pixel(game->line, j + game->dl->begin_x,
				i + game->cast->line_offset, game->dl->color);
		game->dl->ty += game->ray->ty_step;
	}
}

uint32_t	ft_wall_color(t_game *game)
{
	uint32_t	color;

	color = 0;
	if (game->cast->map[(int)game->ray->ray_y / 128]
		[(int)game->ray->ray_x / 128] == 'D')
		color = (int)(game->texture->door->pixels[game->dl->pixel]) << 24
			| (int)(game->texture->door->pixels[game->dl->pixel + 1]) << 16
			| (int)(game->texture->door->pixels[game->dl->pixel + 2]) << 8
			| (int)(game->texture->door->pixels[game->dl->pixel + 3]);
	else if (game->ray->shade == 0.5)
		color = ft_ea_color(game);
	else
		color = ft_no_color(game);
	return (color);
}
