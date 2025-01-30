/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 02:02:32 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-28 02:02:32 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *f, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	double	max_iter;

	zr = 0;
	zi = 0;
	n = 0;
	max_iter = f->max_iter;
	while (n < max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

int	burning_ship(t_fractol *f, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	double	max_iter;

	zr = 0;
	zi = 0;
	n = 0;
	max_iter = f->max_iter;
	while (n < max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

int	julia(t_fractol *f, double zr, double zi)
{
	int		i;
	double	tmp;
	double	kr;
	double	ki;
	double	max_iter;

	max_iter = f->max_iter;
	kr = f->kr;
	ki = f->ki;
	i = 0;
	while (i < max_iter)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + kr;
		zr = zr * zr - zi * zi + ki;
		zi = tmp;
		i++;
	}
	return (i);
}

