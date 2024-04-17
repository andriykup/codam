/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:06:53 by ankupins          #+#    #+#             */
/*   Updated: 2024/03/27 18:06:56 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_argv_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	ft_putstr_fd("inccorrect value for julia, not decimal :(\n", 1);
	exit (1);
}

static int	fract_check(int argc, char **argv, t_fractal *fractal)
{
	if (ft_strlen(argv[1]) == 5 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (argc != 4)
			error_handling(-2);
		ft_argv_check(argv[2]);
		ft_argv_check(argv[3]);
		fractal->x_julia = ft_atof(argv[2]);
		fractal->y_julia = ft_atof(argv[3]);
		return (ft_putstr_fd("your choise is JULIA\n", 1), 1);
	}
	if (ft_strlen(argv[1]) == 10 && ft_strncmp(argv[1],
			"mandelbrot\n", 10) == 0)
		return (ft_putstr_fd("your choise is MANDELBROT\n", 1), 2);
	return (error_handling(-1), -1);
}

void static	my_mlx_terminate(t_fractal *fractal)
{
	mlx_terminate(fractal->mlx);
	exit (1);
}

void	error_handling(int error_code)
{
	if (error_code == -1)
	{
		ft_putstr_fd("\nWRONG INPUT :(\n", 1);
		ft_putstr_fd("avalible options:\n\n", 1);
		ft_putstr_fd("\t1 - julia, remember about two parameters :)\n", 1);
		ft_putstr_fd("\t2 - mandelbrot\n\n", 1);
		exit (1);
	}
	if (error_code == -2)
	{
		ft_putstr_fd("wrong input for julia :(\n", 1);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal.zoom = 1;
	fractal.max_iter = 100;
	if (argc < 2 || argc > 4)
		error_handling(-1);
	fractal.frctl = fract_check(argc, argv, &fractal);
	if (fractal.frctl == -1)
		exit (1);
	fractal.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal.mlx)
		my_mlx_terminate(&fractal);
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	if (fractal.img == NULL)
		my_mlx_terminate(&fractal);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	mlx_loop_hook(fractal.mlx, rendering, &fractal);
	mlx_scroll_hook(fractal.mlx, my_scrooll, &fractal);
	mlx_key_hook(fractal.mlx, ft_hook, fractal.mlx);
	mlx_loop(fractal.mlx);
	my_mlx_terminate(&fractal);
	return (0);
}
