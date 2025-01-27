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

// void zoom(t_env *env, int x, int y, double zoom_factor)
// {
//     double	c_r;
// 	double	c_i;
//     double	x_center;
// 	double	y_center;

// 	x_center = 0.0;
// 	y_center = 0.0;
// 	c_r = 0.0;
// 	c_i = 0.0;
//     if (env->fractal == 1)
// 	{
//     	calc_complex_coords(env, x, y, &c_r, &c_i);
//     	x_center = c_r;
//     	y_center = c_i;
//         // ft_mandelbrot(env);
// 	}
//     else if (env->fractal == 2)
// 	{
// 		c_r = env->complex.cr;
// 		c_i	= env->complex.ci;
// 		calc_complex_coords(env, x, y, &c_r, &c_i);
//     	x_center = c_r;
//     	y_center = c_i;
// 		ft_julia(env, c_r, c_i);
// 	}
//     env->scale.zoom *= zoom_factor;
//     env->scale.xmin = (x_center - (x_center - env->scale.xmin)) * zoom_factor;
//     env->scale.xmax = (x_center + (env->scale.xmax - x_center)) * zoom_factor;
//     env->scale.ymin = (y_center - (y_center - env->scale.ymin)) * zoom_factor;
//     env->scale.ymax = (y_center + (env->scale.ymax - y_center)) * zoom_factor;
// }

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

// int	ft_key_event(int keycode, t_env *env)
// {
// 	double	x_range;
//     double	y_range;

// 	// printf("%d\n", keycode);
// 	// printf("max iter = %f\n", env->scale.max_iter);
// 	x_range = env->scale.xmax - env->scale.xmin;
// 	y_range = env->scale.ymax - env->scale.ymin;
// 	if(keycode == ESC)
// 		ft_close_window(env);
// 	if(keycode == 32)
// 		printf("%f", env->scale.max_iter);
// 	if(keycode >= LEFT && keycode <= DOWN)
// 	{
// 		if(keycode == LEFT)
// 		{
// 			env->scale.xmin -= x_range * 0.05;
//     		env->scale.xmax -= x_range * 0.05;
// 		}
// 		else if(keycode == RIGHT)
// 		{
// 			env->scale.xmin += x_range * 0.05;
//     		env->scale.xmax += x_range * 0.05;
// 		}
// 		else if(keycode == UP)
// 		{
// 			env->scale.ymin -= y_range * 0.05;
//     		env->scale.ymax -= y_range * 0.05;
// 		}
// 		else if(keycode == DOWN)
// 		{
// 			env->scale.ymin += y_range * 0.05;
//     		env->scale.ymax += y_range * 0.05;
// 		}
// 		if(env->fractal == 1)
// 			ft_mandelbrot(env);
// 		if(env->fractal == 2)
// 			ft_julia(env, env->complex.cr, env->complex.ci);
// 		ft_put_image(env);
// 	}
// 	if(keycode == PLUS)
// 		env->scale.max_iter += 1;
// 	if(keycode == MINUS)
// 		env->scale.max_iter -= 1;
// 	if(keycode == ENTER)
// 	{
// 		if (env->fractal == 1)
// 			ft_mandelbrot(env);
// 		if (env->fractal == 2)
// 			ft_julia(env, env->complex.cr, env->complex.ci);
// 		ft_put_image(env);
// 	}
// 	return(0);
// }

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
// 	return (0);

			// 	if(keycode == PLUS)
			// 		f->max_iter += 1;
			// 	if(keycode == MINUS)
			// 		f->max_iter -= 1;
			// 	if(keycode == ENTER)
			// 	{
			// 		if (f->fractal == 1)
			// 			ft_mandelbrot(f);
			// 		if (f->fractal == 2)
			// 			ft_julia(f, f->complex.cr, f->complex.ci);
			// 		ft_put_image(f);
			// 	}
// }

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == ENTER)
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
	// else if (keycode == KEY_SPACE)
	// 	color_shift(mlx);
	// else if (!key_event_extend(keycode, mlx))
	// 	return (1);
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
	// else if (keycode == MOUSE_BTN)
	// {
	// 	if (mlx->set == WHEEL_CLICK)
	// 		julia_shift(x, y, mlx);
	// }
	else
		return (0);
	render(mlx);
	return (0);
}
