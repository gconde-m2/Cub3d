/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:46:00 by gconde-m          #+#    #+#             */
/*   Updated: 2020/03/03 08:18:10 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_struct *x, int stripe)
{
	int y;
	int d;
	int color;

	x->texture_x = (int)(256 * (stripe - (-x->width / 2 +
		x->screen_x)) * TEXTURE_WIDTH / x->width) / 256;
	if (x->transform_y > 0 && stripe > 0 && stripe <
			x->w && x->transform_y < x->z_buffer[stripe])
	{
		y = x->draw_start_y;
		while (y < x->draw_end_y)
		{
			d = (y - x->v_move_screen) * 256 - x->h * 128 +
				x->height * 128;
			x->texture_y = ((d * TEXTURE_HEIGHT) / x->height) / 256;
			color = x->texture[SPRITE_TEXT][TEXTURE_WIDTH *
				x->texture_y + x->texture_x];
			if (color != x->texture[SPRITE_TEXT][0])
				*(x->dataI + (y * x->w) + stripe) = color;
			++y;
		}
	}
}

void	set_start_end(t_struct *x)
{
	x->screen_x = (int)((x->w / 2) * (1 +
						x->transform_x / x->transform_y));
	x->v_move_screen = (int)(VMOVE / x->transform_y);
	x->height = abs((int)(x->h /
											x->transform_y)) / VDIV;
	x->draw_start_y = -x->height / 2 + x->h / 2 +
													x->v_move_screen;
	x->draw_start_y = x->draw_start_y < 0 ? 0 :
													x->draw_start_y;
	x->draw_end_y = x->height / 2 + x->h / 2 +
													x->v_move_screen;
	x->draw_end_y = (x->draw_end_y >= x->h) ?
								x->h - 1 : x->draw_end_y;
	x->width = abs((int)(x->h /
											x->transform_y)) / UDIV;
	x->draw_start_x = -x->width / 2 +
														x->screen_x;
	x->draw_start_x = (x->draw_start_x < 0 ? 0 :
													x->draw_start_x);
	x->draw_end_x = x->width / 2 + x->screen_x;
	x->draw_end_x = (x->draw_end_x >= x->w ?
								x->w - 1 : x->draw_end_x);
}

void	calculate_distances(t_struct *x)
{
	int i;
	i = 0;
	while (i < x->num)
	{
		x->distance[i] = ((x->posx - x->spritex[i]) *
			(x->posx - x->spritex[i]) + (x->posy -
			x->spritey[i]) * (x->posy - x->spritey[i]));
		++i;
	}
	i = 0;
	while (i < x->num)
	{
		x->used[i] = 0;
		++i;
	}
}

void	sprites_casting(t_struct *x)
{
	(void)x;
	int i;
	int k;
	int stripe;

	calculate_distances(x);
	i = -1;
	while (++i < x->num)
	{
		k = get_index(x);
		x->pos_x = x->spritex[k] - x->posx;
		x->pos_y = x->spritey[k] - x->posy;
		x->inv_det = 1.0 / (x->planex * x->diry
								- x->dirx * x->planey);
		x->transform_x = x->inv_det * (x->diry
			* x->pos_x - x->dirx * x->pos_y);
		x->transform_y = x->inv_det *
		(-x->planey * x->pos_x + x->planex *
														x->pos_y);
		set_start_end(x);
		stripe = x->draw_start_x - 1;
		while (++stripe < x->draw_end_x)
			draw_sprite(x, stripe);
	}
	
}