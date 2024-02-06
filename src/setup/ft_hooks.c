/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:57:25 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/05 15:33:12 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_hooks(t_map *map)
{
	ft_set_pixel(map->game->texture->background, WIDTH, HEIGHT, map);
	ft_raycaster(map->game);
	mlx_put_image_to_window(map->game->mlx, map->game->win, map->game->texture->background->mlx_img, 0, 0);
	return (0);
}

int	ft_controls(int key, t_map *map)
{
	if (key == XK_Escape)
		ft_exit(map);
	if (key == XK_Left || key == XK_Right)
		ft_camera_move(map->game, key);
	ft_offset(map->game);
	if (key == 119 || key == 115)
		ft_move_front_back(map->game, key);
	if (key == 97 || key == 100)
		ft_move_vertical(map->game, key);
	return (0);
}


void	ft_camera_move(t_game *game, int key)
{
	if (key == XK_Left)
	{
		game->cast->pa -= 0.1;
		if (game->cast->pa < 0)
			game->cast->pa += 2 * M_PI;
	}
	else if (key == XK_Right)
	{
		game->cast->pa += 0.1;
		if (game->cast->pa < 0)
			game->cast->pa += 2 * M_PI;
	}

}

void	ft_move_front_back(t_game *game, int key)
{
	if (key == 119)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
			[(int)(game->pl_x + game->cast->x_off) / 128]))
				game->pl_x += cos(game->cast->pa) * 6;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y + game->cast->y_off) / 128]
			[(int)game->pl_x / 128]))
				game->pl_y += sin(game->cast->pa) * 6;
	}
	if (key == 115)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
			[(int)(game->pl_x - game->cast->x_off) / 128]))
				game->pl_x -= cos(game->cast->pa) * 6;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y - game->cast->y_off) / 128]
			[(int)game->pl_x / 128]))
				game->pl_y -= sin(game->cast->pa) * 6;
	}
}

void	ft_move_vertical(t_game *game, int key)
{
	if (key == 100)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x + game->cast->x_off_strafe) / 128]))
			game->pl_x += cos(game->cast->pa + M_PI_2) * 6;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y + game->cast->y_off_strafe) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y += sin(game->cast->pa + M_PI_2) * 6;
	}
	else if (key == 97)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x - game->cast->x_off_strafe) / 128]))
			game->pl_x -= cos(game->cast->pa + M_PI_2) * 6;
		if (ft_check_collision(game->cast->map[(int)(game->pl_y
					- game->cast->y_off_strafe) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y -= sin(game->cast->pa + M_PI_2) * 6;
	}
}
