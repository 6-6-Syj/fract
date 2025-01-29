/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 17:14:19 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 17:14:19 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)
*/

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	f->buf[x * 4 + y * WIDTH * 4] = color;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

/* calculate_fractal:
*	Picks the correct fractal calculation function depending
*	on the current fractal set.
*/
static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	nb_iter = 0;
	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	else if (f->set == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	else if (f->set == MANDELBOX)
		nb_iter = mandelbox(f, pr, pi);
	return (nb_iter);
}

/* render:
*	Iterates through each pixel of the window, translates the pixel's
*	coordinates into a complex number to be able to calculate if that number
*	is part of the fractal set or not.
*	The number of iterations that complex number goes through before being
*	rejected from the fractal set determines which color is applied to the pixel.
*	Once all pixels have been assessed and added to the MLX image,
*	this function displays the MLX image to the window.
*/
void	render(t_fractol *f)
{
	int		x;
	int		y;
	int		nb_iter;
	double	pr;
	double	pi;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			if (nb_iter == MAX_ITER)
                f->color = BLACK;
    		else
			{
                f->color = (nb_iter * 6666 / MAX_ITER) << 8;  // Rouge en fonction des itérations
            }
			set_pixel_color(f, x, y, f->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_do_sync(f->mlx);
}

int		close_window(t_fractol *f)
{
	if (!f)
		exit(0);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(1);
}
