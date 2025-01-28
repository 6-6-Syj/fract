/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 17:13:41 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 17:13:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

static void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

/* key_event_extend:
*	Handles events from the keyboard keys:
*		- 1, 2, 3, 4, 5: switch fractals
*	This function is registered to an MLX hook and will
*	automatically be called when the user does anything inside the
*	program window with the keyboard.
*	If a valid event is detected, settings are adjusted and the fractal
*	gets redrawn.
*/
// static int	key_event_extend(int keycode, t_fractol *mlx)
// {
// 	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
// 		mlx->set = MANDELBROT;
// 	else if (keycode == KEY_TWO && mlx->set != JULIA)
// 		mlx->set = JULIA;
// 	else if (keycode == KEY_THREE && mlx->set != BURNING_SHIP)
// 		mlx->set = BURNING_SHIP;
// 	else if (keycode == KEY_FOUR && mlx->set != TRICORN)
// 		mlx->set = TRICORN;
// 	else if (keycode == KEY_FIVE && mlx->set != MANDELBOX)
// 		mlx->set = MANDELBOX;
// 	else
// 		return (1);
// 	get_pxl_complex(mlx);
// 	render(mlx);

// 				if(keycode == PLUS)
// 					f->max_iter += 1;
// 				if(keycode == MINUS)
// 					f->max_iter -= 1;
// 				if(keycode == ENTER)
// 				{
// 					if (f->fractal == 1)
// 						ft_mandelbrot(f);
// 					if (f->fractal == 2)
// 						ft_julia(f, f->complex.cr, f->complex.ci);
// 					ft_put_image(f);
// 				}
// 	return (0);
// }

int	key_event(int keycode, t_fractol *f)
{
	void	*mlx;

	mlx = f->mlx;
	if (keycode == ESC)
	{
		close_window(mlx);
		return (0);
	}
	if (keycode == ENTER)
		zoom(mlx, 0.5);
	else if (keycode == MINUS)
		zoom(mlx, 2);
	else if (keycode == UP)
		move(mlx, 0.2, 'U');
	else if (keycode == DOWN)
		move(mlx, 0.2, 'D');
	else if (keycode == LEFT)
		move(mlx, 0.2, 'L');
	else if (keycode == RIGHT)
		move(mlx, 0.2, 'R');
	else
		return (1);
	render(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_CLICK)
	{
		if (mlx->set == JULIA)
			julia_shift(x, y, mlx);
	}
	else
		return (0);
	render(mlx);
	return (0);
}
