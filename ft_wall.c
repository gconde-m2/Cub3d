/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:49:00 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/01 10:55:36 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting(t_struct *x)
{
	if (x->raydirx < 0)
	{
		x->stepx = -1;
		x->sidedistx = (x->posx - x->mapx) * x->deltadistx;
	}
	else
	{
		x->stepx = 1;
		x->sidedistx = (x->mapx + 1.0 - x->posx) * x->deltadistx;
	}
	if (x->raydiry < 0)
	{
		x->stepy = -1;
		x->sidedisty = (x->posy - x->mapy) * x->deltadisty;
	}
	else
	{
		x->stepy = 1;
		x->sidedisty = (x->mapy + 1.0 - x->posy) * x->deltadisty;
	}
}

void	ft_calculotwo(t_struct *x)
{
	while (x->hit == 0)
	{
		if (x->sidedistx < x->sidedisty)
		{
			x->sidedistx += x->deltadistx;
			x->mapx += x->stepx;
			x->side = 0;
		}
		else
		{
			x->sidedisty += x->deltadisty;
			x->mapy += x->stepy;
			x->side = 1;
		}
		if (x->worldmap[x->mapx][x->mapy] == 1)
			x->hit = 1;
	}
	if (x->side == 0)
		x->perpwalldist = (x->mapx - x->posx + (1 - x->stepx) / 2) / x->raydirx;
	else
		x->perpwalldist = (x->mapy - x->posy + (1 - x->stepy) / 2) / x->raydiry;
	x->lineheight = (int)(x->h / x->perpwalldist);
	x->drawstart = -x->lineheight / 2 + x->h / 2;
}

void	ft_befdraw(t_struct *x)
{
	if (x->side == 0)
		x->wallx = x->posy + x->perpwalldist * x->raydiry;
	else
		x->wallx = x->posx + x->perpwalldist * x->raydirx;
	x->wallx -= floor((x->wallx));
	x->textx = (int)(x->wallx * (double)x->texwidth);
	if (x->side == 0 && x->raydirx > 0)
		x->textx = x->texwidth - x->textx - 1;
	if (x->side == 1 && x->raydiry < 0)
		x->textx = x->texwidth - x->textx - 1;
	x->step = 1.0 * x->texheight / x->lineheight;
	x->texpos = (x->drawstart - x->h / 2 + x->lineheight / 2) * x->step;
	if (x->worldmap[x->mapx][x->mapy] == 1)
		x->color = *x->texture[x->texnum];
}

void	ft_color(t_struct *x)
{
	x->dy = x->mapy - x->posy;
	x->dx = x->mapx - x->posx;
	if (x->drawstart < 0)
		x->drawstart = 0;
	x->drawend = x->lineheight / 2 + x->h / 2;
	if (x->drawend >= x->h)
		x->drawend = x->h - 1;
	if (x->side == 1)
	{
		if (x->dy > 0)
			x->texnum = 0;
		else
			x->texnum = 1;
	}
	else
	{
		if (x->dx > 0)
			x->texnum = 2;
		else
			x->texnum = 3;
	}
	ft_befdraw(x);
}

void	ft_draw(t_struct *x)
{
	while (x->n < x->drawstart)
	{
		x->color = (x->cealing_red * 256 * 256) + (x->cealing_green * 256)
												+ x->cealing_blue;
		*(x->datai + (x->n * x->w)) = x->color;
		x->n++;
	}
	while (x->n <= x->drawend)
	{
		x->texty = (int)x->texpos & (x->texheight - 1);
		x->texpos += x->step;
		x->color = x->texture[x->texnum][x->texheight * x->texty + x->textx];
		*(x->datai + (x->n * x->w)) = x->color;
		x->n++;
	}
	while (x->n < x->h)
	{
		x->color = (x->floor_red * 256 * 256) + (x->floor_green * 256)
												+ x->floor_blue;
		*(x->datai + (x->n * x->w)) = x->color;
		x->n++;
	}
}
