/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readinglast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 06:48:50 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/03 07:17:36 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_read_map(t_struct *x, char *line)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(line);
	x->map_width = x->map_width < (int)len ? (int)len : x->map_width;
	if (x->map_str == NULL)
		temp = ft_strdup(line);
	else
		temp = ft_strjoin(x->map_str, line);
	free(x->map_str);
	x->map_str = temp;
	temp = ft_strjoin(x->map_str, "\n");
	free(x->map_str);
	x->map_str = temp;
	x->map_height++;
}

void		ft_readtextures(t_struct *x, char *line)
{
	if (*line == 'N' && *(line + 1) == 'O')
		ft_texturehelpingread(x, line, 0);
	else if (*line == 'S' && *(line + 1) == 'O')
		ft_texturehelpingread(x, line, 1);
	else if (*line == 'W' && *(line + 1) == 'E')
		ft_texturehelpingread(x, line, 2);
	else if (*line == 'E' && *(line + 1) == 'A')
		ft_texturehelpingread(x, line, 3);
	else if (*line == 'S')
		ft_texturehelpingread(x, line, 4);
	else
		ft_exitinerror(x);
}

void		ft_validate_map(t_struct *x)
{
	if (ft_validate_map_2(x, (int)(x->posx - 0.5),
	(int)(x->posy - 0.5)) == 1)
		ft_exitinerror(x);
	ft_mdf_map(x);
}

void		ft_mdf_map(t_struct *x)
{
	int	row;
	int	col;

	row = -1;
	while (++row < x->map_height)
	{
		col = -1;
		while (++col < x->map_width)
		{
			if (x->worldmap[row][col] == 4)
				x->worldmap[row][col] = 0;
			else if (x->worldmap[row][col] == 5)
				x->worldmap[row][col] = 2;
		}
	}
}

void		ft_check(t_struct *x, char *line)
{
	if (*line == 'R')
		ft_readres(x, line);
	else if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
		ft_readtextures(x, line);
	else if (*line == 'F')
		check_floor_color(x, line);
	else if (*line == 'C')
		check_cealing_color(x, line);
	else if (ft_isdigit(*line) || *line == ' ')
		ft_read_map(x, line);
	else if (*line != '\0')
		ft_exitinerror(x);
}
