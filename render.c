/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:11:26 by aenstein          #+#    #+#             */
/*   Updated: 2021/02/28 13:27:01 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static void		pixel_put(t_rtv *rtv, int x, int y, int color)
{
	int		i;

	i = (x * rtv->window->bit_per_pixel / 8) + (y * rtv->window->size_line);
	rtv->window->data_addr[i] = color;
	rtv->window->data_addr[++i] = color >> 8;
	rtv->window->data_addr[++i] = color >> 16;
}

static int		get_color(t_rtv *rtv, t_vector *o, t_vector *d, t_t *t)
{
	double	closest_t;
	double	ans;
	int		color;

	ans = discriminant(scalar(d, d), 2.0 * scalar(minus_vect(o, rtv->figure->c),
		d), scalar(minus_vect(o, rtv->figure->c),
			minus_vect(o, rtv->figure->c)) - pow(rtv->figure->r, 2));
	if (ans == INFINT)
		return (WHITE);
	color = compute_lighting(rtv, sum_vect(o, mult_num_vect(ans, d)),
		del_vect_num(minus_vect(sum_vect(o, mult_num_vect(ans, d)), rtv->figure->c),
		vect_legth(minus_vect(sum_vect(o, mult_num_vect(ans, d)), rtv->figure->c))), reverse_vect(d));
	return (color);
	return (0);
}

void	render(t_rtv *rtv)
{
	int			x;
	int			y;
	int			color;
	t_vector	*cur;

	x = 0;
	while (x <  WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			cur = create_vec(x - HALFCW, HALFCH - y);
			color = get_color(rtv, zero_vec(), cur, create_t());
			// ft_printf("%d ", color);
			pixel_put(rtv, x, y, color);
			y++;
		}
		x++;
		// ft_printf("x - %d y - %d:  ", x, y);
	}
	mlx_put_image_to_window(rtv->window->mlx, rtv->window->win,
		rtv->window->img, 0, 0);
}