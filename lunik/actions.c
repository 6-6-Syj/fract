/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 22:27:54 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-03 22:27:54 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fractol *f, double distance, char direction)
{
	double		width;
	double		height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += width * distance;
		f->max_r += width * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= width * distance;
		f->max_r -= width * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += height * distance;
		f->max_i += height * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= height * distance;
		f->max_i -= height * distance;
	}
}

void	zoom(t_fractol *f, int x, int y, double factor)
{
	double	mouse_r;
	double	mouse_i;
	double	new_width;
	double	new_height;

	mouse_r = f->min_r + (f->max_r - f->min_r) * x / WIDTH;
	mouse_i = f->max_i - (f->max_i - f->min_i) * y / HEIGHT;
	new_width = (f->max_r - f->min_r) * factor;
	new_height = (f->max_i - f->min_i) * factor;
	f->min_r = mouse_r - (mouse_r - f->min_r) * factor;
	f->max_r = f->min_r + new_width;
	f->min_i = mouse_i - (mouse_i - f->min_i) * factor;
	f->max_i = f->min_i + new_height;
}
