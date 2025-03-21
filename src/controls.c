/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:51:51 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 16:22:40 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_fractol *f)
{
    if (keycode == 65307) // ESC to exit
        exit(0);
    if (keycode == 65361) // Left arrow
        f->x_start -= 0.1 * f->zoom, f->x_end -= 0.1 * f->zoom;
    if (keycode == 65363) // Right arrow
        f->x_start += 0.1 * f->zoom, f->x_end += 0.1 * f->zoom;
    if (keycode == 65362) // Up arrow
        f->y_start -= 0.1 * f->zoom, f->y_end -= 0.1 * f->zoom;
    if (keycode == 65364) // Down arrow
        f->y_start += 0.1 * f->zoom, f->y_end += 0.1 * f->zoom;
    if (keycode == 65451) // '+' to zoom in
        f->zoom *= 0.9;
    if (keycode == 65453) // '-' to zoom out
        f->zoom *= 1.1;
    
    render_julia(f, f->c_julia.real, f->c_julia.img); // Only update after all movements
    return (0);
}
int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	double	mouse_real = f->x_start + (x / (double)WIDTH) * (f->x_end - f->x_start);
	double	mouse_imag = f->y_start + (y / (double)HEIGHT) * (f->y_end - f->y_start);
	double	zoom_factor = (button == ZOOM_IN) ? 0.9 : 1.1;

	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		if ((f->zoom < 50 && button == ZOOM_IN) || (f->zoom > 0.1 && button == ZOOM_OUT))
		{
			f->x_start = mouse_real + (f->x_start - mouse_real) * zoom_factor;
			f->x_end = mouse_real + (f->x_end - mouse_real) * zoom_factor;
			f->y_start = mouse_imag + (f->y_start - mouse_imag) * zoom_factor;
			f->y_end = mouse_imag + (f->y_end - mouse_imag) * zoom_factor;
			f->zoom *= zoom_factor;

			mlx_clear_window(f->mlx_init_ptr, f->mlx_win_ptr);
			if (f->c_julia.real || f->c_julia.img)
				render_julia(f, f->c_julia.real, f->c_julia.img);
			else
				render_mandelbrot(f);
		}
	}
	return (0);
}

int	close_window(t_fractol *f)
{
	mlx_destroy_window(f->mlx_init_ptr, f->mlx_win_ptr);
	exit(0);
	return (0);
}