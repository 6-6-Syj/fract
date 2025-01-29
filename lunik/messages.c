/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 18:26:46 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 18:26:46 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* print_fractal_options:
*	Prints an explanation of the fractal options that can be specified
*	at program launch.
*/
void	print_fractal_options(void)
{
	ft_putendl_fd("\033[36m________________________________________________\n\033[0m", 1);
	ft_putendl_fd("Select a fractal with a letter:", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("\tX - Mandelbox", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0", 1);
	ft_putendl_fd("\e[36mExample:\t", 1);
	ft_putendl_fd("./fractol J\n\t\t./fractol J 0.285 0.01\e[0m", 1);
	ft_putendl_fd("\033[36m________________________________________________\n", 1);
}

/* print_controls:
*	Prints a list of program controls to the standard output when the program
*	launches successfully.
*/
void	print_controls(void)
{
	ft_putendl_fd("\033[36m________________________________________________", 1);
	ft_putendl_fd("\n\t\t\033[1\033[36m\033[4mCONTROLS\033[0m\n", 1);
	ft_putendl_fd("Arrow keys:\t\t\t\033[0mMove view", 1);
	ft_putendl_fd("Scroll wheel:\t\t\t\033[0mZoom in and out", 1);
	ft_putendl_fd("Left click:\t\t\t\033[0mShift Julia set", 1);
	// ft_putendl_fd("1, 2, 3, 4:\t\t\t\033[0mSwitch fractals", 1);
	ft_putendl_fd("ESC or close window:\t\t\033[0mQuit fract'ol", 1);
	ft_putendl_fd("\033[36m________________________________________________\n", 1);
}

/* help_msg:
*	Prints a help message to the standard output to explain the program options.
*/
void	help_msg(t_fractol *f)
{
	print_fractal_options();
	close_window(f);
}

/* msg:
*	Displays an error message to the standard error.
*	Returns the provided error number.
*/
void	message(t_fractol *f, char *str1, char *str2)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	close_window(f);
}

