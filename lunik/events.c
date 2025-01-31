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

static int	key_event_change_set(int keycode, t_fractol *f)
{
	if ((keycode == KEY_ONE || keycode == NUM_1) && f->set != MANDELBROT)
		f->set = MANDELBROT;
	else if ((keycode == KEY_TWO || keycode == NUM_2) && f->set != JULIA)
		f->set = JULIA;
	else if ((keycode == KEY_THREE || keycode == NUM_3)
		&& f->set != BURNING_SHIP)
		f->set = BURNING_SHIP;
	else if ((keycode == KEY_FOUR || keycode == NUM_4) && f->set != MANDELBOX)
		f->set = MANDELBOX;
	else
		return (1);
	get_complex_range(f);
	render(f);
	return (0);
}

static int	key_event_move(int keycode, t_fractol *f)
{
	if (keycode == UP)
		move(f, 0.05, 'U');
	else if (keycode == DOWN)
		move(f, 0.05, 'D');
	else if (keycode == LEFT)
		move(f, 0.05, 'L');
	else if (keycode == RIGHT)
		move(f, 0.05, 'R');
	render(f);
	return (0);
}

static int	key_event_iter(int keycode, t_fractol *f)
{
	if (keycode == PLUS)
	{
		f->modify_iter += 1;
		printf("Iterations will be: %.0f\n", f->modify_iter);
	}
	else if (keycode == MINUS && f->modify_iter > 2)
	{
		f->modify_iter -= 1;
		ft_printf("Iterations will be: %.0f\n", f->modify_iter);
	}
	else if (keycode == ENTER)
	{
		f->max_iter = f->modify_iter;
		ft_printf("Calculated with %f iterations\n", f->max_iter);
		render(f);
	}
	return (0);
}

int	key_event(int keycode, t_fractol *f)
{
	void	*mlx;
	int		handled;

	mlx = f->mlx;
	handled = 0;
	if (keycode == SUPPR)
	{
		get_complex_range(f);
		render(f);
	}
	if (keycode == ESC)
	{
		close_window(f);
		return (0);
	}
	handled |= !key_event_move(keycode, f);
	handled |= !key_event_iter(keycode, f);
	handled |= !key_event_change_set(keycode, f);
	if (handled)
		render(f);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == WHEEL_UP)
	{
		zoom(f, x, y, 0.9);
		if (f->set == JULIA)
			f->zoom_julia += 1;
	}
	else if (keycode == WHEEL_DOWN)
	{
		zoom(f, x, y, 1.1);
		if (f->set == JULIA)
			f->zoom_julia -= 1;
	}
	else if (keycode == MOUSE_CLICK)
	{
		if (f->set == JULIA)
		{
			if (f->zoom_julia == 0)
				julia_shift(x, y, f);
			else
				ft_putendl_fd("Zoom out to shift another julia' set", 1);
		}
	}
	render(f);
	return (0);
}
