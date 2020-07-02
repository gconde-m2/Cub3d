/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 08:12:14 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/01 11:19:13 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_floor_color(t_struct *x, char *line)
{
	if (x->floor_red == -1)
	{
		while (*line == ' ' || *line == 'F')
			line++;
		if ((x->floor_red = ft_atoi(line)) < 0 &&
												x->floor_red > 255)
			ft_exitinerror(x);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if ((x->floor_green = ft_atoi(line)) < 0 &&
												x->floor_green > 255)
			ft_exitinerror(x);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if ((x->floor_blue = ft_atoi(line)) < 0 &&
												x->floor_blue > 255)
			ft_exitinerror(x);
	}
	else
		ft_exitinerror(x);
}

void	check_cealing_color(t_struct *x, char *line)
{
	if (x->cealing_red == -1)
	{
		while (*line == ' ' || *line == 'C')
			line++;
		if ((x->cealing_red = ft_atoi(line)) < 0 &&
												x->cealing_red > 255)
			ft_exitinerror(x);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if ((x->cealing_green = ft_atoi(line)) < 0 &&
												x->cealing_green > 255)
			ft_exitinerror(x);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if ((x->cealing_blue = ft_atoi(line)) < 0 &&
												x->cealing_blue > 255)
			ft_exitinerror(x);
	}
	else
		ft_exitinerror(x);
}

void	ft_readreserror(t_struct *x, char *line)
{
	(void)line;
	if (x->w <= 0 || x->h <= 0 || !x->h || !x->w)
		ft_exitinerror(x);
	else
	{
		if (x->w < 200)
			x->w = 200;
		else if (x->w > 2560)
			x->w = 2560;
		if (x->h > 1440)
			x->h = 1440;
		else if (x->h < 200)
			x->h = 200;
	}
}

void	ft_readres(t_struct *x, char *line)
{
	if (*line == 'R')
	{
		line++;
		while (*line == ' ')
			line++;
		while (*line >= '0' && *line <= '9')
		{
			x->w = x->w * 10 + (*line - '0');
			line++;
		}
		if (*line == ' ')
		{
			line++;
			while (*line >= '0' && *line <= '9')
			{
				x->h = x->h * 10 + (*line - '0');
				line++;
			}
		}
		ft_readreserror(x, line);
	}
}

void	ft_texturehelpingread(t_struct *x, char *line, int i)
{
	int h;
	int w;

	h = 0;
	w = 0;
	line = line + 2;
	while (*line == ' ')
		++line;
	if (!(open(line, O_RDONLY)))
		ft_exitinerror(x);
	x->texture_ptr[i] = mlx_xpm_file_to_image(x->mlx_ptr, line, &h, &w);
	x->texture[i] = (int*)mlx_get_data_addr(x->texture_ptr[i],
					&x->bits, &x->size_line, &x->endian);
	if (open(line, O_RDONLY) < 0)
		ft_exitinerror(x);
}
