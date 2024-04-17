/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:08:33 by ankupins          #+#    #+#             */
/*   Updated: 2024/04/07 18:08:35 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractal *fractal, int max_iter)
{
	int	iterations;

	fractal->constant.real = 0;
	fractal->constant.imgn = 0;
	iterations = iterate_fractal(fractal->constant, fractal->pixel, max_iter);
	return (iterations);
}

int	julia(t_fractal *fractal, int max_iter)
{
	int	iterations;

	fractal->constant.real = fractal->x_julia;
	fractal->constant.imgn = fractal->y_julia;
	iterations = iterate_fractal(fractal->pixel, fractal->constant, max_iter);
	return (iterations);
}

int	iterate_fractal(t_complex c, t_complex z, int max_iter)
{
	int		iterations;
	double	real;
	double	imgn_l;

	iterations = 0;
	while (iterations < max_iter)
	{
		real = c.real * c.real - c.imgn * c.imgn + z.real;
		imgn_l = 2 * c.real * c.imgn + z.imgn;
		c.real = real;
		c.imgn = imgn_l;
		if (c.real * c.real + c.imgn * c.imgn > 4)
			break ;
		iterations++;
	}
	return (iterations);
}
