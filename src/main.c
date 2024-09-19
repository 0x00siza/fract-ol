/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:57:45 by ner-roui          #+#    #+#             */
/*   Updated: 2024/09/19 20:01:52 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
	{
		draw_julia(fractal);
	}
	else if (ft_strncmp(name, "ship", 5) == 0)
		draw_burning_ship(fractal);
	else
	{
		ft_putendl_fd("Available fractals: mandelbrot, julia, ship", 2);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	ft_error(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
	exit(1);
}

void	fractal_init(t_fractal *fractal)
{
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
	|| (4 == argc && !ft_strncmp(argv[1], "julia", 5))
	|| (2 == argc && !ft_strncmp(argv[1], "burningship", 10)))
	{
		fractal = malloc(sizeof(t_fractal));
		fractal -> name = argv[1];
		fractal_init(fractal);
		if (ft_strncmp(fractal -> name, "julia", 6) == 0)
		{
			if (argc == 4)
			{
				fractal->cx = atodbl(argv[2]);
				fractal->cy = atodbl(argv[3]);
			}
			else
				exit_fractal(fractal);
		}
		draw_fractal(fractal, argv[1]);
		mlx_loop(fractal->mlx);
	}
	else
		ft_error();
}
// / -0.745429
	//  0.05