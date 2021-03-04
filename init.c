/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:41:23 by aenstein          #+#    #+#             */
/*   Updated: 2021/02/27 16:58:04 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_window	*init_win()
{
	t_window	*window;

	window = (t_window *)ft_memalloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "RTv1");
	window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->data_addr = mlx_get_data_addr(window->img, &(window->bit_per_pixel),
		&(window->size_line), &(window->endian));
	return (window);
}

t_rtv		*init_rtv(t_window *window)
{
	t_rtv		*rtv;

	rtv = (t_rtv *)ft_memalloc(sizeof(t_rtv));
	rtv->window = window;
	return (rtv);
}