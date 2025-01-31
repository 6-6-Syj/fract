/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 17:26:51 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 17:26:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	type_cmp(char *av, char *str, char c)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && av[0] == c)
		return (1);
	return (0);
}

static void	get_set(t_fractol *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm'))
		f->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j'))
		f->set = JULIA;
	else if (type_cmp(av[1], "burning_ship", 'b'))
		f->set = BURNING_SHIP;
	else if (type_cmp(av[1], "mandelbox", 'x'))
		f->set = MANDELBOX;
	else
	{
		print_fractal_options();
		close_window(f);
	}
}

static int	get_julia_starting_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->kr = -0.766667;
		f->ki = -0.09;
		return (1);
	}
	if (ac == 3)
	{
		ft_putendl_fd("\033[31mIncorrect number of arguments\033[0m", 1);
		return (0);
	}
	if (!ft_strchr(av[2], '.'))
	{
		ft_putendl_fd("\033[31mNo '.' found in 1st parameter\033[0m", 1);
		return (0);
	}
	if (!ft_strchr(av[3], '.'))
	{
		ft_putendl_fd("\033[31mNo '.' found in 2nd parameter\033[0m", 1);
		return (0);
	}
	f->kr = ft_atof(av[2]);
	f->ki = ft_atof(av[3]);
	if (f->kr > 2.0 || f->kr < -2.0)
	{
		ft_putendl_fd("\033[31mValues must be between -2.0 & 2.0.\033[0m", 1);
		return (0);
	}
	if (f->ki >= 2.0 || f->ki <= -2.0)
	{
		ft_putendl_fd("\033[31mValues must be between -2.0 & 2.0.\033[0m", 1);
		return (0);
	}
	return (1);
}

static int	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 2)
	{
		print_fractal_options();
		ft_putendl_fd("\033[31mIncorrect number of arguments\033[0m", 1);
		return (0);
	}
	else if (f->set == JULIA && ac > 5)
	{
		print_fractal_options();
		ft_putendl_fd("\033[31mIncorrect number of arguments\033[0m", 1);
		return (0);
	}
	if(get_julia_starting_values(f, ac, av))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
	{
		print_fractal_options();
		return (0);
	}
	init_struct(&f); 				// init struct		// verify args
	if (!(handle_args(&f, ac, av)))
		return (0);
	init(&f); 						// init window + default values
	render(&f);						// render image
	print_controls();				// prints help
	mlx_hook(f.win, 17, 1L << 0, close_window, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
	return (0);
}
