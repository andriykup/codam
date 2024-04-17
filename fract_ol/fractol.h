/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:07:09 by ankupins          #+#    #+#             */
/*   Updated: 2024/03/27 18:07:11 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <X11/keysym.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 1700
# define HEIGHT 1700

typedef struct s_comples
{
	double	real;
	double	imgn;
}	t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_complex	constant;
	t_complex	pixel;
	int			max_iter;
	double		zoom;
	double		x_julia;
	double		y_julia;
	int			x;
	int			y;
	int			frctl;
}	t_fractal;

void			error_handling(int error_code);
void			ft_hook(mlx_key_data_t keydata, void *param);
mlx_resizefunc	ft_mouse(int button, int x, int y, void *fractal);
void			my_scrooll(double xdelta, double ydelta,
					void *param);
void			rendering(void *data);
int				mandelbrot(t_fractal *fractal, int max_iter);
int				julia(t_fractal *fractal, int max_iter);
int				determine_colour(int iterations, int max_iter);
void			draw_pixels(t_fractal *fractal, int x, int y);
int				iterate_fractal(t_complex z, t_complex c, int max_iter);
double			scale_coordinate_y(t_fractal *fractal, int y);
double			scale_coordinate_x(t_fractal *fractal, int x);
double			ft_atof(char *str);
int				ft_atoi(const char *nptr);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
