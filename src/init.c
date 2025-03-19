/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:56:40 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 23:44:07 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	create_window(t_fractol *fractol)
{
	fractol->mlx_win_ptr = mlx_new_window(fractol->mlx_init_ptr, WIDTH, HEIGHT, fractol->title);
	if (!fractol->mlx_win_ptr)
	{
		free(fractol->mlx_init_ptr);
		ft_put_err("Error: Failed to create window\n", 2);
		exit(1);
	}
}

void	create_image(t_fractol *fractol)
{
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_init_ptr, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_init_ptr, fractol->mlx_win_ptr);
		ft_put_err("Error: Failed to create image\n", 2);
		exit(1);
	}
	fractol->img.pix_data = mlx_get_data_addr(fractol->img.img_ptr,
		&fractol->img.bit_pix, &fractol->img.line_len, &fractol->img.endian);
}

void	initialize_fractol(t_fractol *fractol)
{
	fractol->mlx_init_ptr = mlx_init();
	if (!fractol->mlx_init_ptr)
	{
		ft_put_err("Error: Failed to initialize MiniLibX\n", 2);
		exit(1);
	}
	create_window(fractol);
	create_image(fractol);
	setup_fractal(fractol);  // Assuming `plan` is for setting up the fractal
	initialize_events(fractol);
}