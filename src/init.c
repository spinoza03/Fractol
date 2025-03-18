/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:56:40 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 16:55:29 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractol(t_fractal *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		printf("Error: Failed to initialize MLX\n");
		exit(1);
	}
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol->win)
	{
		printf("Error: Failed to create window\n");
		exit(1);
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, 
										&fractol->img.line_length, &fractol->img.endian);
}