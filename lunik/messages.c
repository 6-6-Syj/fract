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

void	print_fractal_options(void)
{
	ft_putendl_fd("\033[36m______________________________________________", 1);
	ft_putendl_fd("\n\033[0m", 1);
	ft_putendl_fd("Select a fractal with a letter:", 1);
	ft_putendl_fd("\tm - Mandelbrot", 1);
	ft_putendl_fd("\tj - Julia", 1);
	ft_putendl_fd("\tb - Burning Ship", 1);
	ft_putendl_fd("\tx - Mandelbox", 1);
	ft_putendl_fd("\n\e[36mEx:\t./fractol <type>\n\t./fractol M\e[0m", 1);
	ft_putendl_fd("\nFor Julia, you may specify starting values for", 1);
	ft_putendl_fd("the initial fractal. ", 1);
	ft_putendl_fd("Default values set at -0.766667 -0.09.", 1);
	ft_putendl_fd("Values must be between -2.0 and 2.0.", 1);
	ft_putendl_fd("\n\e[36mEx:\t./fractol J\n\t./fractol J 0.285 0.01\e[0m", 1);
	ft_putendl_fd("\033[36m______________________________________________", 1);
	ft_putendl_fd("\033[0m", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\033[36m______________________________________________", 1);
	ft_putendl_fd("\n\t\t\033[1\033[36m\033[4mCONTROLS\033[0m\n", 1);
	ft_putendl_fd("Arrow keys\t\tMove view", 1);
	ft_putendl_fd("Scroll wheel\t\tZoom in and out", 1);
	ft_putendl_fd("SUPPR\t\t\tReset zoom", 1);
	ft_putendl_fd("Left click\t\tShift Julia set", 1);
	ft_putendl_fd("1, 2, 3, 4\t\tSwitch fractals", 1);
	ft_putendl_fd("ESC or close window\tQuit fract'ol", 1);
	ft_putendl_fd("+ / -\t\t\tAdd or deduct\n\t\t\titeration number", 1);
	ft_putendl_fd("ENTER\t\t\tCalculate fractal with", 1);
	ft_putendl_fd("\t\t\tnew iteration number", 1);
	ft_putendl_fd("\033[36m______________________________________________", 1);
	ft_putendl_fd("\033[0m", 1);
}

void	print_help(void)
{
	ft_putendl_fd("\033[36m______________________________________________", 1);
	ft_putendl_fd("\n\t\t\033[1\033[36m\033[4mCONTROLS\033[0m\n", 1);
	ft_putendl_fd("Arrow keys\t\t\tMove view", 1);
	ft_putendl_fd("Scroll wheel\t\t\tZoom in and out", 1);
	ft_putendl_fd("SUPPR\t\t\t\tReset zoom", 1);
	ft_putendl_fd("Left click\t\t\tShift Julia set", 1);
	ft_putendl_fd("1, 2, 3, 4\t\t\tSwitch fractals", 1);
	ft_putendl_fd("ESC or close window\t\tQuit fract'ol", 1);
	ft_putendl_fd("+ / -\t\t\t\tAdd or deduct iteration nb", 1);
	ft_putendl_fd("ENTER\t\t\t\tCalculate fractal with new iteration nb", 1);
	ft_putendl_fd("\033[36m______________________________________________", 1);
	ft_putendl_fd("\n\033[0m", 1);
}

void	message(t_fractol *f, char *str1, char *str2)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	close_window(f);
}
