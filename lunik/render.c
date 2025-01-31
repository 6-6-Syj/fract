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

static void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;
	int		line_length;
	int		bpp;
	char	*addr;

	line_length = data->line_length;
	bpp = data->bits_per_pixel * 0.125;
	addr = data->addr;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pxl = addr + (y * line_length + x * bpp);
		*(unsigned int *)pxl = color;
	}
}

static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	nb_iter = 0;
	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(f, pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	else if (f->set == BURNING_SHIP)
		nb_iter = burning_ship(f, pr, pi);
	else if (f->set == MANDELBOX)
		nb_iter = mandelbox(f, pr, pi);
	return (nb_iter);
}

static void	set_pixel_color(t_fractol *f, int x, int y, int nb_iter)
{
	double	max_iter;

	max_iter = f->max_iter;
	if (nb_iter == max_iter)
		ft_put_pixel(&f->data, x, y, BLACK);
	else
		ft_put_pixel(&f->data, x, y, ((double)nb_iter * WHITE / max_iter));
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	int		nb_iter;
	double	pr;
	double	pi;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(f, x, y, nb_iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->data.img, 0, 0);
	mlx_do_sync(f->mlx);
}

int		close_window(t_fractol *f)
{
	if (!f)
		exit(0);
	if (f->data.img)
		mlx_destroy_image(f->mlx, f->data.img);
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
