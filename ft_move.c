/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:44:38 by gconde-m          #+#    #+#             */
/*   Updated: 2020/03/03 07:56:19 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int key, t_struct *x)
{
	if (key == 13)
		x->kw = 1;
	if (key == 123)
		x->karrowright = 1;
	if (key == 1)
		x->ks = 1;
	if (key == 124)
		x->karrowleft = 1;
	if (key == 0)
		x->ka = 1;
	if (key == 2)
		x->kd = 1;
	if (key == 53)
		cubexit(x);
	return (0);
}

int	key_released(int key, t_struct *x)
{
	if (key == 13)
		x->kw = 0;
	if (key == 123)
		x->karrowright = 0;
	if (key == 1)
		x->ks = 0;
	if (key == 124)
		x->karrowleft = 0;
	if (key == 0)
		x->ka = 0;
	if (key == 2)
		x->kd = 0;
	return (0);
}

void	move_up_down(t_struct *x)
{
	if (x->ks == 1 || x->kw == 1)
	{
		if (x->ks == 1 && x->speed > 0)
			x->speed *= -1;
		if (x->kw == 1 && x->speed < 0)
			x->speed *= -1;
		if (x->worldMap[(int)(x->posx + x->dirx * x->speed)][(int)x->posy] == 0)
			x->posx += x->dirx * x->speed;
		if (x->worldMap[(int)x->posx][(int)(x->posy + x->diry * x->speed)] == 0)
			x->posy += x->diry * x->speed;
	}
}

void	rotate(t_struct *x)
{
	if (x->ka == 1 || x->kd == 1)
	{
		if (x->ka == 1 && x->speed > 0)
			x->rotspeed *= -1;
		if (x->kd == 1 && x->speed < 0)
			x->rotspeed *= -1;
		if (x->worldMap[(int)(x->posx + x->planex *
							x->rotspeed)][(int)(x->posy)] == 0)
			x->posx += x->planex * x->rotspeed;
		if (x->worldMap[(int)(x->posx)][(int)(x->posy +
										x->planey * x->rotspeed)] == 0)
			x->posy += x->planey * x->rotspeed;
	}
}

int	move_draw(t_struct *x)
{
	x->rotspeed = x->speed / 2.2;
	move_up_down(x);
	if (x->karrowleft == 1 || x->karrowright == 1)
	{
		if (x->karrowleft == 1 && x->speed > 0)
			x->speed *= -1;
		if (x->karrowright == 1 && x->speed < 0)
			x->speed *= -1;
		x->old_dirx = x->dirx;
		x->dirx = x->dirx * cos(x->speed / 4) - x->diry * sin(x->speed / 4);
		x->diry = x->old_dirx * sin(x->speed / 4) + x->diry * cos(x->speed / 4);
		x->old_planex = x->planex;
		x->planex = x->planex * cos(x->speed / 4) -
									x->planey * sin(x->speed / 4);
		x->planey = x->old_planex * sin(x->speed / 4) +
									x->planey * cos(x->speed / 4);
	}
	rotate(x);
	ft_calculo(x);
	sprites_casting(x);
	if (x->bmpflag == 0)
		mlx_put_image_to_window(x->mlx_ptr, x->win_ptr, x->image, 0, 0);
	else
		makebmp(x);
	return (0);
}
