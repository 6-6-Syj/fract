/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 23:31:03 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-03 23:31:03 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->set = -1;
	f->zoom_julia = 0;
	f->name = NULL;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->max_iter = 0;
	f->modify_iter = 0;
	f->data.img = NULL;
	f->data.addr = NULL;
	f->data.bits_per_pixel = 0;
	f->data.line_length = 0;
	f->data.endian = 0;
}

static void	get_complex_range_more(t_fractol *f)
{
	if (f->set == MANDELBROT)
	{
		f->name = "Mandelbrot";
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
		else if (f->set == BURNING_SHIP)
	{
		f->name = "Burning Ship";
		f->min_r = -2.2;
		f->max_r = 0.8;
		f->max_i = -2.0;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	get_complex_range(t_fractol *f)
{
	if (f->set == JULIA)
	{
		f->name = "Julia";
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
		f->zoom_julia = 0;
	}
	get_complex_range_more(f);
}

static void	init_img(t_fractol *f)
{
	f->data.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->data.img))
	{
		ft_putendl_fd("\033[31mError creating image\033[0m\n", 1);
		close_window(f);
	}
	f->data.addr = mlx_get_data_addr(f->data.img, &f->data.bits_per_pixel,
			&f->data.line_length, &f->data.endian);
}

void	init(t_fractol *f)
{
	if (WIDTH == 0 || HEIGHT == 0)
	{
		ft_putendl_fd("\033[31mUnvalid size of window\033[0m\n", 1);
		exit(1);
	}
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_putendl_fd("\033[31mError creating MLX instance\033[0m\n", 1);
		close_window(f);
	}
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	f->max_iter = MAX_ITER;
	f->modify_iter = MAX_ITER;
	get_complex_range(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	if (!f->win)
	{
		ft_putendl_fd("\033[31mError creating window\033[0m\n", 1);
		close_window(f);
	}
	init_img(f);
}
