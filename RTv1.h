/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:31:06 by aenstein          #+#    #+#             */
/*   Updated: 2021/03/04 17:03:29 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "minilibx_macos/mlx.h"
# include "lib/includes/header.h"
# include <math.h>

# define	HEIGHT		1000
# define	WIDTH		1000
# define	HALFCW		500
# define	HALFCH		500

# define	SPHERE		1
# define	CYLINDER	2
# define	CONE		3
# define	PLANE		4

# define	BLACK		0x000000
# define	RED			0xff0000
# define	GREEN		0x00ff00
# define	BLUE		0x0000ff
# define	WHITE		0xffffff
# define	YELLOW		0xffff00

# define	PI			3.1416
# define	INFINT		2147483647

// gcc *.c *.h lib/libftprintf.a minilibx_macos/libmlx.a -lmlx -framework OpenGL -framework AppKit

typedef struct	s_t
{
	double			t_min;
	double			t_max;
}				t_t;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_camera
{
	t_vector		*c;
	t_vector		*v;
}				t_camera;

typedef	struct	s_window
{
	char	*data_addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
}				t_window;

typedef	struct	s_figure
{
	t_vector		*c;
	t_vector		*v;
	double			angle;
	double			r;
	double			specular;
	int				color;
	int				type;
	struct s_figure *next;
}				t_figure;

typedef struct	s_light
{
	t_vector		*c;
	double			power;
	struct s_light	*next;
}				t_light;

typedef struct	s_d
{
	double			x;
	double			y;
	double			d;
}				t_d;


typedef struct	s_rtv
{
	t_camera	*camera;
	t_window	*window;
	t_figure	*figure;
	t_light		*light;
	t_light		*light_first;
	double		ambient;
}				t_rtv;

// ** основыне

void	render(t_rtv *rtv);
t_window	*init_win();
t_rtv		*init_rtv(t_window *window);

// ** help

t_vector	*minus_vect(t_vector *a, t_vector *b);
t_t			*create_t();
t_vector	*zero_vec();
t_vector		*create_vec(double x, double y);
double		scalar(t_vector *a, t_vector *b);
double		discriminant(double a, double b, double c);
int			compute_lighting(t_rtv *rtv, t_vector *p, t_vector *n, t_vector *v);
t_vector	*sum_vect(t_vector *a, t_vector *b);
t_vector	*mult_num_vect(double i, t_vector *a);
double		vect_legth(t_vector *a);
t_vector	*del_vect_num(t_vector *a, double i);
t_vector			*reverse_vect(t_vector *a);
t_vector			*mult_vect(t_vector *a, t_vector *b);

// ** debag 
void	sphere(t_figure *sphere);
void	ft_light(t_light *light);

#endif