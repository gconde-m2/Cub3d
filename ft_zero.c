/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:33:07 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/01 10:50:51 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_tozero(t_struct *x)
{
	x->bits = 4;
	x->endian = 1;
	x->speed = 0.25;
	x->texwidth = 64;
	x->texheight = 64;
	x->cealing_red = -1;
	x->cealing_green = -1;
	x->cealing_blue = -1;
	x->floor_red = -1;
	x->floor_green = -1;
	x->floor_blue = -1;
	x->map_str = ft_strdup("");
}
