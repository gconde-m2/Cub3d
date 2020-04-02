/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:44:06 by gconde-m          #+#    #+#             */
/*   Updated: 2020/02/25 07:13:57 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_index(t_struct *x)
{
	int active_index;
	int i;

	i = 0;
	active_index = 0;
	while (i < x->num)
	{
		if (x->used[i] == 0)
			break ;
		++i;
	}
	active_index = i;
	i = 0;
	while (i < x->num)
	{
		if (x->distance[active_index] < x->distance[i] &&
													x->used[i] == 0)
			active_index = i;
		++i;
	}
	x->used[active_index] = 1;
	return (active_index);
}

void	get_x_y(t_struct *x)
{
	int y;
	int z;
	int i;

	z = 0;
	i = 0;
	while (z < x->map_height)
	{
		y = 0;
		while (y < x->map_width)
		{
			if (x->worldMap[z][y] == 2)
			{
				x->spritex[i] = z + 0.6;
				x->spritey[i] = y + 0.6;
				i++;
			}
			++y;
		}
		++z;
	}
}

int		sprites_init(t_struct *x)
{
	if (x->dir == 'N')
	{
		x->dirx = -1;
		x->planey = 0.66;
	}
	if (x->dir == 'S')
	{
		x->dirx = 1;
		x->planey = -0.66;
	}
	if (x->dir == 'E')
	{
		x->diry = 1;
		x->planex = 0.66;
	}
	if (x->dir == 'W')
	{
		x->diry = -1;
		x->planex = -0.66;
	}
	if (!(x->used = (int*)malloc(sizeof(int) * x->num)))
		return (0);
	if (!(x->distance = (double*)malloc(sizeof(double) *
															x->num)))
		return (0);
	if (!(x->spritex = (double*)malloc(sizeof(double) *
															x->num)))
		return (0);
	if (!(x->spritey = (double*)malloc(sizeof(double) *
															x->num)))
		return (0);
	if (!(x->z_buffer = (double*)malloc(sizeof(double) *
													x->w)))
		return (0);
	get_x_y(x);
	return (1);
}
