/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-31 20:13:29 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-31 20:13:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
	{
		print_fractal_options();
		return (0);
	}
	init_struct(&f);
	if (!(handle_args(&f, ac, av)))
		return (0);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, 17, 1L << 0, close_window, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
	return (0);
}
