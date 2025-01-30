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
void move(t_fractol *f, double distance, char direction)
{
    double width = f->max_r - f->min_r;
    double height = f->max_i - f->min_i;

    if (direction == 'R')
    {
        f->min_r += width * distance;
        f->max_r += width * distance;
    }
    else if (direction == 'L')
    {
        f->min_r -= width * distance;
        f->max_r -= width * distance;
    }
    else if (direction == 'U')
    {
        f->min_i += height * distance;
        f->max_i += height * distance;
    }
    else if (direction == 'D')
    {
        f->min_i -= height * distance;
        f->max_i -= height * distance;
    }
}

int	key_event(int keycode, t_fractol *f)
{
	void	*mlx;

	mlx = f->mlx;
	if (keycode == ESC)
	{
		close_window(f);
		return (0);
	}
	else if(keycode == PLUS)
	{
		f->modify_iter += 1;
		printf("max_iter =%f\n", f->modify_iter);
	}
	else if(keycode == MINUS && f->modify_iter > 0)
	{
		f->modify_iter -= 1;
		printf("max_iter =%f\n", f->modify_iter);
	}
	else if (keycode == ENTER)
	{
		f->max_iter = f->modify_iter;
		printf("f->max_iter = %f\n", f->max_iter);
		render(f);
	}
	else if (keycode == UP)
		move(f, 0.05, 'U');
	else if (keycode == DOWN)
		move(f, 0.05, 'D');
	else if (keycode == LEFT)
		move(f, 0.05, 'L');
	else if (keycode == RIGHT)
		move(f, 0.05, 'R');
	// else
	// 	return (0);
	render(f);
	return (0);
}

void zoom(t_fractol *f, int x, int y, double factor)
{
    double mouse_r = f->min_r + (f->max_r - f->min_r) * x / WIDTH;
    double mouse_i = f->max_i - (f->max_i - f->min_i) * y / HEIGHT;

    double new_width = (f->max_r - f->min_r) * factor;
    double new_height = (f->max_i - f->min_i) * factor;

    f->min_r = mouse_r - (mouse_r - f->min_r) * factor;
    f->max_r = f->min_r + new_width;
    f->min_i = mouse_i - (mouse_i - f->min_i) * factor;
    f->max_i = f->min_i + new_height;
}


int mouse_event(int keycode, int x, int y, t_fractol *f)
{
    if (keycode == WHEEL_UP)
    {
        zoom(f, x, y, 0.9);
    }
    else if (keycode == WHEEL_DOWN)
    {
        zoom(f, x, y, 1.1);
    }
    else if (keycode == MOUSE_CLICK)
    {
        if (f->set == JULIA)
            julia_shift(x, y, f);
    }
    else
        return (0);
    render(f);
    return (0);
}
