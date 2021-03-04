/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:32:26 by aenstein          #+#    #+#             */
/*   Updated: 2021/02/27 20:47:42 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		key_press(int key, t_rtv *rtv)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_rtv		*rtv;
	t_window	*window;
	t_figure	*figure;
	t_light		*light;

	window = init_win();
	rtv = init_rtv(window);
	figure = (t_figure *)ft_memalloc(sizeof(t_figure));
	light = (t_light *)ft_memalloc(sizeof(t_light));
	sphere(figure);
	ft_light(light);
	rtv->figure = figure;
	rtv->light = light;
	mlx_hook(rtv->window->win, 2, 0, key_press, rtv);
	render(rtv);
	mlx_loop(rtv->window->mlx);
	return (0);
}
