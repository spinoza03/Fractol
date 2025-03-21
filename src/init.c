/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:58:48 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 15:33:29 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mlx(t_fractol *f, char *title)
{
	f->mlx_init_ptr = mlx_init();
	if (!f->mlx_init_ptr)
	{
		ft_putstr_fd("Error: MLX initialization failed\n", 2);
		exit(1);
	}
	f->mlx_win_ptr = mlx_new_window(f->mlx_init_ptr, WIDTH, HEIGHT, title);
	if (!f->mlx_win_ptr)
	{
		ft_putstr_fd("Error: Window creation failed\n", 2);
		exit(1);
	}
}

void	init_image(t_fractol *f)
{
	f->img.img_ptr = mlx_new_image(f->mlx_init_ptr, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
	{
		ft_putstr_fd("Error: Image creation failed\n", 2);
		mlx_destroy_window(f->mlx_init_ptr, f->mlx_win_ptr);
		exit(1);
	}
	f->img.pix_data = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bit_pix, &f->img.line_len, &f->img.endian);
}

void	init_fractol(t_fractol *f, char *title)
{
	init_mlx(f, title);
	init_image(f);
	f->zoom = 1.0;
	f->iter_n = MAX_ITER;
	f->x_start = -2.0;
	f->x_end = 2.0;
	f->y_start = -2.0;
	f->y_end = 2.0;
	f->c_julia.real = 0.0;
	f->c_julia.img = 0.0;
}
