/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:02:39 by ankupins          #+#    #+#             */
/*   Updated: 2024/04/03 16:02:40 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rendering(void *data)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = data;
	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			draw_pixels(fractal, x, y);
			x++;
		}
		y++;
	}
}

void	draw_pixels(t_fractal *fractal, int x, int y)
{
	int	colour;
	int	iterations;

	iterations = 0;
	fractal->pixel.real = scale_coordinate_x(fractal, x);
	fractal->pixel.imgn = scale_coordinate_y(fractal, y);
	if (fractal->frctl == 2)
	{
		iterations = mandelbrot(fractal, fractal->max_iter);
	}
	else if (fractal->frctl == 1)
	{
		iterations = julia(fractal, fractal->max_iter);
	}
	colour = determine_colour(iterations, fractal->max_iter);
	mlx_put_pixel(fractal->img, x, y, colour);
}

double	scale_coordinate_y(t_fractal *fractal, int y)
{
	double	center;
	double	inverted_y;

	center = HEIGHT / 2.0;
	inverted_y = HEIGHT - y;
	y = inverted_y - center;
	return (y * (4.0 * fractal->zoom) / HEIGHT);
}

double	scale_coordinate_x(t_fractal *fractal, int x)
{
	double	center;

	center = WIDTH / 2.0;
	return ((x - center) * (4.0 * fractal->zoom) / WIDTH);
}

int	determine_colour(int iterations, int max_iter)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iter)
		return (0x000000);
	else
	{
		red = (iterations * 8) % 255;
		green = (iterations * 15) % 255;
		blue = (iterations * 9) % 255;
		return ((red << 16) | (green << 8) | blue);
	}
}
