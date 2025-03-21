/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:01:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 16:13:41 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	update_fractal(t_fractol *f)
{
	mlx_clear_window(f->mlx_init_ptr, f->mlx_win_ptr);
	if (f->c_julia.real || f->c_julia.img)
		render_julia(f, f->c_julia.real, f->c_julia.img);
	else
		render_mandelbrot(f);
}

int	main_loop(t_fractol *f)
{
	update_fractal(f);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;
	double		real, imag;
	int i = 1;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		init_fractol(&fractol, av[1]);
		render_mandelbrot(&fractol);
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (!pars_args(av[2], av[3]))
		{
			ft_putstr_fd("Invalid arguments\n", 2);
			return (1);
		}
		real = ft_atof(av[2], &i);
		imag = ft_atof(av[3], &i);
		init_fractol(&fractol, av[1]);
		fractol.c_julia.real = real;
		fractol.c_julia.img = imag;
		render_julia(&fractol, real, imag);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot OR ./fractol julia <real> <imag>\n", 2);
		return (1);
	}

	mlx_key_hook(fractol.mlx_win_ptr, key_hook, &fractol);
	mlx_mouse_hook(fractol.mlx_win_ptr, mouse_hook, &fractol);
	mlx_hook(fractol.mlx_win_ptr, 17, 0, close_window, &fractol);

	mlx_loop_hook(fractol.mlx_init_ptr, main_loop, &fractol); // Redraws only when needed
	mlx_loop(fractol.mlx_init_ptr);
	return (0);
}
