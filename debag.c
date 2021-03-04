/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:03:54 by aenstein          #+#    #+#             */
/*   Updated: 2021/02/28 14:35:35 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	sphere(t_figure *sphere)
{
	t_vector	*c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	sphere->c = c;
	sphere->c->x = 0;
	sphere->c->y = 0;
	sphere->c->z = 5;
	sphere->r = 1;
	sphere->specular = 10;
	sphere->color = RED;
}

void	ft_light(t_light *light)
{
	t_vector	*c;

	c = (t_vector *)ft_memalloc(sizeof(t_vector));
	light->c = c;
	light->c->x = 4;
	light->c->y = 0;
	light->c->z = 1;
	light->power = 0.4;
}