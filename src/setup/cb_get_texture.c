/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:23 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 03:03:32 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_get_draw_texture(t_game *game, t_map *map)
{

	game->texture->background->mlx_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->texture->background->addr = mlx_get_data_addr(game->texture->background->mlx_img, &game->texture->background->bpp, &game->texture->background->line, &game->texture->background->endian);
	ft_set_pixel(game->texture->background, WIDTH, HEIGHT, map);
}
