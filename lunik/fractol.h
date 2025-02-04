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
# define WIDTH 500
# define HEIGHT 500

// ITERATIONS
# define MAX_ITER 130

// SET
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

// MOUSE
# define LEFT_CLICK 1
# define WHEEL_CLICK 2
# define RIGHT_CLICK 3
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define MOUSE_CLICK 1

// KEYBOARD
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define PLUS 65451
# define MINUS 65453
# define ENTER 65421
# define SUPPR 65288

# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define KEY_FOUR 52
# define NUM_1 65436
# define NUM_2 65433
# define NUM_3 65435
# define NUM_4 65430

// COLOR
# define BLACK 0x00000000
# define WHITE 0xFFFFBFFF

# include <stdlib.h>
# include <math.h>
# include <ctype.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	int				set;
	int				zoom_julia;
	char			*name;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			kr; // Julia
	double			ki; // Julia
	double			sx; // default value (init.c - init)
	double			rx;	// default value (init.c - init)
	double			fx;	// default value (init.c - init)
	double			max_iter;
	double			modify_iter;
	t_data			data;
}					t_fractol;

// init.c
void	init_struct(t_fractol *f);
void	get_complex_range(t_fractol *f);
void	init(t_fractol *f);

// render.c
void	render(t_fractol *f);
int		close_window(t_fractol *f);

// sets.c
int		mandelbrot(t_fractol *f, double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
int		julia_shift(int x, int y, t_fractol *f);
int		burning_ship(t_fractol *f, double cr, double ci);
int		mandelbox(t_fractol *f, double cr, double ci);

// events.c
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

// actions.c
void	move(t_fractol *f, double distance, char direction);
void	zoom(t_fractol *f, int x, int y, double factor);

// messages.c
void	print_fractal_options(void);
void	print_controls(void);
void	message(t_fractol *f, char *str1, char *str2);

// args.c
int		handle_args(t_fractol *f, int ac, char **av);
int		type_cmp(char *av, char *str, char c);
int		get_julia_starting_values(t_fractol *f, int ac, char **av);
void	get_set(t_fractol *f, char **av);

#endif
