/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:24:55 by gconde-m          #+#    #+#             */
/*   Updated: 2020/03/03 06:46:25 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_floorcalc(t_struct *x)
{
	x->raydirx0 = x->dirx - x->planex;
	x->raydiry0 = x->diry - x->planey;
	x->raydirx1 = x->dirx + x->planex;
	x->raydiry1 = x->diry + x->planey;
	x->p = x->y - x->h / 2;
	x->posz = 0.5 * x->h;
	x->rowdistance = x->posz / x->p;
	x->floorstepx = x->rowdistance * (x->raydirx1 - x->raydirx0) / x->w;
	x->floorstepy = x->rowdistance * (x->raydiry1 - x->raydiry0) / x->w;
	x->floorx = x->posx + x->rowdistance * x->raydirx0;
	x->floory = x->posy + x->rowdistance * x->raydiry0;
}

void	ft_cellcalc(t_struct *x)
{
	x->texwidth = 64;
	x->texheight = 64;
	x->cellx = (int)(x->floorx);
	x->celly = (int)(x->floory);
	x->tx = (int)(x->texwidth * (x->floorx - x->cellx)) & (x->texwidth - 1);
	x->ty = (int)(x->texheight * (x->floory - x->celly)) & (x->texheight - 1);
	x->floorx += x->floorstepx;
	x->floory += x->floorstepy;
	x->floortexture = 5;
	x->ceilingtexture = 4;
}

void	ft_floorcasting(t_struct *x)
{
	x->y = x->h / 2 + 1;
	while (x->y < x->h)
	{
		ft_floorcalc(x);
		x->z = 0;
		while (x->z < x->w)
		{
			ft_cellcalc(x);
			x->color = x->texture[x->floortexture][x->texwidth * x->ty + x->tx];
			*(x->datai + (x->y * x->w) + x->z) = x->color;
			x->color = x->texture[x->ceilingtexture]
						[x->texwidth * x->ty + x->tx];
			*(x->datai + ((x->h - x->y - 1) *
						x->w) + x->z) = x->color;
			x->z++;
		}
		x->y++;
	}
}
