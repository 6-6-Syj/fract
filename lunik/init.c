/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 17:14:08 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 17:14:08 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
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
	// f->palette = NULL;
	// f->color_pattern = -1;
	// f->color = 0;
}

void	get_pxl_complex(t_fractol *f)
{
	if (f->set == MANDELBOX)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

/* init_img:
*	Initializes an MLX image and a color palette. The color palette will
*	be used to store every shade of color for every iteration number,
*	and the color of each pixel will be stored in the image, which will
*	then be displayed in the program window.
*/
static void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	// f->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	// if (!(f->palette))
	// 	clean_exit(msg("error initializing color scheme.", "", 1), f);
	// f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	// if (!(f->img))
	// 	clean_exit(msg("image creation error.", "", 1), f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

// /* reinit_image:
// *	Cleanly reinitializes the MLX image if the color palette or
// *	fractal type is modified at runtime.
// */
void	init_img_again(t_fractol *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	// if (f->palette)
	// 	free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

// /* init:
// *	Creates a new MLX instance, a new window and populates
// *	the fractol data structure with default values.
// */
void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	// if (!f->mlx)
	// 	clean_exit(msg("MLX: error connecting to mlx.", "", 1), f);
	// f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	// if (!f->win)
	// 	clean_exit(msg("MLX: error creating window.", "", 1), f);
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	get_pxl_complex(f);
	// color_shift(f);
}
