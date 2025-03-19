/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:46:45 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 23:46:57 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	close_window(t_fractol *f)
{
	mlx_destroy_image(f->mlx_init_ptr, f->img.img_ptr);
	mlx_destroy_window(f->mlx_init_ptr, f->mlx_win_ptr);
	exit(0);
	return (0);
}

static int	handle_keypress(int key, t_fractol *f)
{
	if (key == 53) // Escape key
		close_window(f);
	return (0);
}

static int	handle_zoom(int key, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	
	if (key == 4)      // Scroll up
		f->zoom = 1.05;
	else if (key == 5) // Scroll down
		f->zoom = 0.95;
	else
		return (0);
	
	fract_creat(f, f->title);
	return (0);
}

void	init_events(t_fractol *f)
{
	mlx_hook(f->mlx_win_ptr, 17, 0, close_window, f);     // Close window event
	mlx_hook(f->mlx_win_ptr, 2, 0, handle_keypress, f);   // Key press event
	mlx_mouse_hook(f->mlx_win_ptr, handle_zoom, f);       // Mouse zoom event
}