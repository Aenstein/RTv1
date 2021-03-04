/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:52:35 by aenstein          #+#    #+#             */
/*   Updated: 2021/02/28 14:34:39 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector			*mult_vect(t_vector *a, t_vector *b)
{
	t_vector 	*c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	c->x = a->x * b->x;
	c->y = a->y * b->y;
	c->z = a->z * b->z;
	return (c);
}

t_vector			*reverse_vect(t_vector *a)
{
	t_vector 	*c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	c->x = -(a->x);
	c->y = -(a->y);
	c->z = -(a->z);
	return (c);
}

static int			calc_color(int color, double i)
{
	uint8_t		color_p[3];
	int			new_color;
	
	new_color = 0;
	color_p[0] = color >> 16;
	color_p[1] = color >> 8;
	color_p[2] = color;
	color_p[0] = (double)color_p[0] * i;
	color_p[1] = (double)color_p[1] * i;
	color_p[2] = (double)color_p[2] * i;
	new_color = color_p[0] << 16;
	new_color += color_p[1] << 8;
	new_color += color_p[2];
	return (new_color);
}

t_vector	*del_vect_num(t_vector *a, double i)
{
	t_vector 	*c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	c->x = a->x / i;
	c->y = a->y / i;
	c->z = a->z / i;
	return (c);
}

double		vect_legth(t_vector *a)
{
	return (sqrt(pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2)));
}

t_vector	*mult_num_vect(double i, t_vector *a)
{
	t_vector 	*c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	c->x = a->x * i;
	c->y = a->y * i;
	c->z = a->z * i;
	return (c);
}

t_vector	*sum_vect(t_vector *a, t_vector *b)
{
	t_vector *c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
	return (c);
}

int		compute_lighting(t_rtv *rtv, t_vector *p, t_vector *n, t_vector *v)
{
	double		i;
	double		dot;
	int			color;
	t_vector	*l;

	i = 0;
	color = rtv->figure->color;
	l = (t_vector *)ft_memalloc(sizeof(t_vector));
	l = minus_vect(rtv->light->c, p);
	dot = scalar(n, l);
	if (dot > 0)
		i += (rtv->light->power * dot) / (vect_legth(n) * vect_legth(l));
	i += 0.3;
	// зеркальность
	if (rtv->figure->specular != -1)
	{
		l = minus_vect(mult_num_vect(2 * scalar(n, l), n), l);
		dot = scalar(l, v);
		if (dot > 0)
			i += rtv->light->power * pow(dot / (vect_legth(l) * vect_legth(v)), rtv->figure->specular);
	}
	if (i > 1.0)
	{
		color = 0xffffff;
		i = 1.0;
	}
	color = calc_color(color, i);
	return (color);
}

t_vector	*minus_vect(t_vector *a, t_vector *b)
{
	t_vector *c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
	return (c);
}

t_t			*create_t()
{
	t_t		*cur;

	cur = (t_t *)ft_memalloc(sizeof(t_t));
	cur->t_max = INFINT;
	cur->t_min = 1;
	return (cur);
}

t_vector	*zero_vec()
{
	t_vector	*vector;

	vector = (t_vector *)ft_memalloc(sizeof(t_vector));
	return (vector);
}

t_vector		*create_vec(double x, double y)
{
	t_vector		*new;

	new = (t_vector *)ft_memalloc(sizeof(t_vector));
	new->x = x / WIDTH;
	new->y = y / HEIGHT;
	new->z = 1;
	return (new);
}

double		scalar(t_vector *a, t_vector *b)
{
	double		ans;

	ans = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
	return (ans);
}

double		discriminant(double a, double b, double c)
{
	double		x1;
	double		x2;
	double	d;
	double	ans;

	// ft_printf("a - %f, b - %f, c - %f ", a, b, c);
	d = pow(b, 2) - 4 * a * c;
	// ft_printf("%f ", d);
	if (d < 0)
		return (INFINT);
	x1 = (-b + sqrt(d)) / (2 * a);
	x2 = (-b - sqrt(d)) / (2 * a);
	// ft_printf("%f ", x1);
	if (x2 > 1 && x2 < INFINT)
		return (x2);
	else if (x1 > 1 && x1 < INFINT)
		return (x1);
	else
		return (INFINT);
}