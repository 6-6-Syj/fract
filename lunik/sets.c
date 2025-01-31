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

int burning_ship(t_fractol *f, double cr, double ci)
{
    double zr;
    double zi;
    double zr2;
    double zi2;
    int n;

	zr = 0.0;
	zi = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	n = 0;
    while (n < f->max_iter)
    {
        zr2 = zr * zr;
        zi2 = zi * zi;
        if (zr2 + zi2 > 4.0)
            return (n);
        zi = fabs(2 * zr * zi) + ci;
        zr = fabs(zr2 - zi2) + cr;
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

int julia(t_fractol *f, double zr, double zi)
{
    double zr2;
	double zi2;
    int n;

	n = 0;
    while (n < f->max_iter)
    {
        zr2 = zr * zr;
        zi2 = zi * zi;
        if (zr2 + zi2 > 4.0)
            return (n);
        if (n > 0 && fabs(zr - f->kr) < 1e-6 && fabs(zi - f->ki) < 1e-6)
            return (f->max_iter);
        zi = 2 * zr * zi + f->ki;
        zr = zr2 - zi2 + f->kr;
        n++;
    }
    return (n);
}





