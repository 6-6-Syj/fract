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
# define WIDTH 1000
# define HEIGHT 1000

// ITERATIONS
# define MAX_ITER 77

// SET
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define MANDELBOX 4

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

// COLOR
# define BLACK 0x00000000
# define WHITE 0xFFFFBFFF

# include <stdlib.h>
# include <math.h>
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
} 				t_data;

typedef struct 		s_fractol
{
	void			*mlx;
	void			*win;
	int				set;
	char			*name;
	double 			min_r;
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
// void	init_img_again(t_fractol *f);

// render.c
void	render(t_fractol *f);
int		close_window(t_fractol *f);

// sets
int		mandelbrot(t_fractol *f, double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
int		julia_shift(int x, int y, t_fractol *f);
int		burning_ship(t_fractol *f, double cr, double ci);
int		mandelbox(t_fractol *f, double cr, double ci);

//  events.c
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

// messages.c
void	print_fractal_options(void);
void	print_controls(void);
void	help_msg(t_fractol *f);
void	message(t_fractol *f, char *str1, char *str2);

// args
double	ft_atof(char *str);

# endif
