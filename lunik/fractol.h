/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 17:13:01 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 17:13:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// WINDOW
# define WIDTH 800
# define HEIGHT 800

// FRACTAL
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define MANDELBOX 4
# define MAX_ITER 50

// MOUSE
# define LEFT_CLICK 1
# define WHEEL_CLICK 2
# define RIGHT_CLICK 3
# define WHEEL_UP 4
# define WHEEL_DOWN 5
// MOUSE_BTN

// KEYBOARD
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define PLUS 65451
# define MINUS 65453
# define ENTER 65421

// COLOR
// # define BLACK 0x00000000
// # define WHITE 0xFFFFBFFF

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*buf;
	int			set;
	double 		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		kr; // Julia
	double		ki; // Julia
	double		sx;
	double		rx;
	double		fx;
	double		max_iter;
}				t_fractol;

// init.c
void	init_struct(t_fractol *f);
void	get_pxl_complex(t_fractol *f);
void	init(t_fractol *f);
void	init_img_again(t_fractol *f);

// madelbrot.c
int		mandelbrot(double cr, double ci);

// julia.c
int		julia(t_fractol *f, double zr, double zi);
// int	julia_shift(int x, int y, t_fractol *f);

// burningship.c
int		burning_ship(double cr, double ci);

// mandelbox.c
int		mandelbox(t_fractol *f, double cr, double ci);

//  events.c
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

// messages.c
void	print_fractal_options(void);
void	print_color_options(void);
void	print_controls(void);
void	help_msg(t_fractol *f);

#endif
