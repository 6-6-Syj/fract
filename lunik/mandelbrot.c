/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 21:17:16 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-30 21:17:16 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	bud_test(double cr, double ci)
{
	if ((cr + 1) * (cr + 1) + ci * ci <= 0.0625)
		return (1);
	return (0);
}

static int	cardiod_test(double cr, double ci)
{
	double	p;

	p = (cr - 0.25) * (cr - 0.25) + ci * ci;
	if (p * (p + (cr - 0.25)) <= 0.25 * ci * ci)
		return (1);
	return (0);
}

static int	mandelbrot_test(double cr, double ci)
{
	if (bud_test(cr, ci) || cardiod_test(cr, ci))
		return (1);
	return (0);
}

int	mandelbrot(t_fractol *f, double cr, double ci)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		n;

	zr = 0.0;
	zi = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	n = 0;
	if (mandelbrot_test(cr, ci))
		return (f->max_iter);
	while (n < f->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			return (n);
		zi = (zr + zr) * zi + ci;
		zr = zr2 - zi2 + cr;
		n++;
	}
	return (n);
}
