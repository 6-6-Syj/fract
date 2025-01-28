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

/* mandelbrot:
*   Checks whether a complex number is part of the Mandelbrot set or not.
*   Takes as parameters the real and imaginary coordinates of a point,
*   converted previously from a pixel's coordinates.
*   Returns the number of iterations before the number escapes
*   the Mandelbrot set, which can then be used to determine coloring.
*/
int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITER)
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
/*
    How it works:

    The Mandelbrot formula iterates over complex numbers:
    At every iteration, Z is squared.
        Z = Z * Z + c
    If the result tends toward infinity, that means it is not part of
    the set. If the result stays small over several iterations, the number
    is part of the set.

    Examples with regular numbers:
        ex.: c = 1
            Z =  0
            Z =  0 *  0 + 1 = 1
            Z =  1 *  1 + 1 = 2
            Z =  2 *  2 + 1 = 5
            Z =  5 *  5 + 1 = 26
            Z = 26 * 26 + 1 = 677
            ... Grows to infinity.
            So 1 is NOT part of the Mandelbrot set.

        ex.2: c = -1
            Z =    0
            Z =    0 *    0 + (-1) = -1
            Z = (-1) * (-1) + (-1) =  0
            Z =    0 *    0 + (-1) = -1
            ... Result oscillates between -1 and 0
            So -1 is part of the Mandelbrot set.

    Here we can't compute to infinity but it's safe to say that if the
    absolute value of Z goes above 2, it will tend toward infinity and
    the number won't be part of the Mandelbrot set.

    Since we are working with complex numbers, we need to calculate the
    real number Zr and the imaginary number Zi and evaluate both together.
    Multiplication of 2 complex numbers is complicated:
    (a + bi)2   = (a + bi) * (a + bi)
                = (a * a) + (a * bi) + (a * bi) + (bi * bi)
                = (a * a) - (bi * bi) + 2 * (a * bi)
    So the multiplication formula for the imaginary part is:
                    (a * a) - (bi * bi)
    And the multiplication formula for the real part is:
                    2 * a * bi

    See:    http://warp.povusers.org/Mandelbrot/
            https://www.mathsisfun.com/algebra/complex-number-multiply.html
*/

/* burning_ship:
*	Checks whether a complex number is part of the Burning Ship set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes
*	the Burning Ship set, which can then be used to determine coloring.
*/
int	burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITER)
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

/*
	How it works:

	The Burning Ship fractal is a distortion of the Mandelbrot
	fractal. It uses the same equation to calculate the set, but
	uses absolute values of zr and zi at each iteration.
*/

/* julia_shift:
*	Changes the Julia calculation kr and ki values to get a different Julia
*	fractal shape. This function should be called when the user clicks on
*	a point on the screen.
*/

int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

/* julia:
*	Checks whether a complex number is part of the Julia set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes
*	the Julia set, which can then be used to determine coloring.
*/
int	julia(t_fractol *f, double zr, double zi)
{
	int		i;
	double	tmp;
	double	kr;
	double	ki;

	kr = f->kr;
	ki = f->ki;
	i = 0;
	while (i < MAX_ITER)
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
/*
	How it works:

	The Julia set is closely related to the Mandelbrot set:
	its formula is identical. What differs are the complex
	number we plug into it.

	Mandelbrot uses 0 as a starting value for zr and zi, and
	adds pixel coordinates (cr and ci) every time it iterates.

	On the other hand, Julia starts with pixel coordinates as
	zr and zi and adds another complex number (kr and ki) every time
	it iterates.

	kr and ki values determine the shape Julia will take on.
	If kr + ki is part of the Mandelbrot set, Julia will be a continuous
	solid shape. If kr + ki is not part of the Mandelbrot set, the
	Julia fractal will be a disconnected set of separate islands.
	If kr + ki is a point that is close to the Mandelbrot fractal boundary,
	the same patterns we see at that point in the Mandelbrot fractal
	will emerge in the Julia fractal.
*/
