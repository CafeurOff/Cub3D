/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:10:03 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:33:50 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_raycaster(t_game *game)
{
	game->ray->rays = -1;
	game->ray->ray_a = game->cast->pa - 0.0174533 * 30;
	ft_set_value(game);
	ft_replace_texture(game);
	//if (SKY == 1)
		//draw_sky(g); // LORENZO ICI POTO
	while (++game->ray->rays < game->ray->n_of_rays)
	{
		ft_line_honrizontal(game);
		ft_line_vertical(game);
		ft_check_distance(game);
		ft_set_ray_val(game);
	}
}

void	ft_set_value(t_game *game)
{
	if (game->ray->ray_a < 0)
		game->ray->ray_a += 2 * M_PI;
	if (game->ray->ray_a > 2 * M_PI)
		game->ray->ray_a -= 2 * M_PI;
}

void	ft_replace_texture(t_game *game)
{
	if (game->line)
		mlx_delete_image(game->mlx, game->line);
	game->line = mlx_new_image(game->mlx, game->dis_w + 20, game->dis_h + 20);
	mlx_image_to_window(game->mlx, game->line, 0, 0);
	game->line->instances[0].z = 0;
}

double	ft_get_distance(t_game *g, double bx, double by)
{
	double	ax;
	double	ay;

	ax = g->pl_x;
	ay = g->pl_y;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	ft_set_ray_val(t_game *game)
{
	ft_set_cos(game);
	ft_set_render(game);
	ft_draw_walls(game);
	//if (FLOOR == 1)
		//ft_set_values_floor_ceiling(game); // LORENZO ICI POTO
	game->ray->ray_a += 0.0174533 / 8;
	ft_set_value(game);
}