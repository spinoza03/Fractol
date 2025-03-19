/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:01:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 23:59:26 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;
	double		real, imag;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		init_fractol(&fractol);
		render_mandelbrot(&fractol);
		mlx_loop(fractol.mlx);
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (!pars_args(av[2], av[3]))
		{
			ft_putstr_fd("Invalid arguments\n", 2);
			return (1);
		}
		real = atof(av[2]);
		imag = atof(av[3]);
		init_fractol(&fractol);
		render_julia(&fractol, real, imag);
		mlx_loop(fractol.mlx);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot OR ./fractol julia <real> <imag>\n", 2);
		return (1);
	}
	return (0);
}