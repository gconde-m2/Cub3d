/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readinglast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 06:48:50 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/03 07:17:36 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_and_set_values(t_struct *x, int i, int j)
{
	if (*x->map_str == 'N' || *x->map_str == 'S' ||
								*x->map_str == 'E' || *x->map_str == 'W')
	{
		if (x->posy == 0)
		{
			x->posx = i + 0.5;
			x->posy = j + 0.5;
			x->dir = *x->map_str;
		}
		else
			ft_exitinerror(x);
	}
	else
	{
		if (*x->map_str == '0' || *x->map_str == '1' || *x->map_str == ' '
														|| *x->map_str == '2')
			x->worldMap[i][j] = *x->map_str - '0';
		else
			ft_exitinerror(x);
	}
	if (x->worldMap[i][j] == 2)
		x->num++;
	x->map_str++;
}

static void	check_and_set_map(t_struct *x)
{
	int i;
	int j;

	if (!(x->worldMap = (int**)ft_calloc(x->map_height, sizeof(int*))))
		ft_exitinerror(x);
	i = -1;
	while (++i < x->map_height)
	{
		if (!(x->worldMap[i] = (int*)ft_calloc(x->map_width, sizeof(int))))
			ft_exitinerror(x);
		j = -1;
		while (++j < x->map_width)
		{
			if (*x->map_str == '\n')
			{
				while (j < x->map_width)
					x->worldMap[i][j++] = -1;
				x->map_str++;
				break ;
			}
			check_and_set_values(x, i, j);
		}
		if (*x->map_str == '\n')
			x->map_str++;
	}
}

void		ft_check_map(t_struct *x)
{
	int i;
	int j;

	(void)x;
	j = 0;
	i = 0;
	while (i < x->map_height)
	{
		j = 0;
		while (j < x->map_width)
		{
			if (x->worldMap[i][j] < 0 && ((i != 0 &&
x->worldMap[i - 1][j] == 0) || (j != 0 && (x->worldMap[i][j - 1] == 0))))
				ft_exitinerror(x);
			if (x->worldMap[i][j] < 0 && ((i != 0 &&
x->worldMap[i - 1][j] == 2) || (j != 0 && (x->worldMap[i][j - 1] == 2))))
				ft_exitinerror(x);
			if ((x->worldMap[i][j] == 0 || x->worldMap[i][j] == 2) &&
			(i == 0 || j == 0 || i == x->map_height || j == x->map_width ||
				x->worldMap[i - 1][j] < 0 || x->worldMap[i][j - 1] < 0))
				ft_exitinerror(x);
			j++;
		}
		++i;
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
	free(line);
}

void		reading_all(t_struct *x, char *s1)
{
	int		fd;
	char	*line;

	if (!(fd = open(s1, O_RDONLY)))
		ft_exitinerror(x);
	while ((x->zread = get_next_line(fd, &line)) >= 0)
	{
		ft_check(x, line);
		if (x->zread == 0)
		{
			while (x->texture[x->zread] && x->zread < 4)
				x->zread++;
			if (x->zread != 4)
				ft_exitinerror(x);
			if (x->map_height < 3 || x->map_width < 3)
				ft_exitinerror(x);
			check_and_set_map(x);
			ft_check_map(x);
			if (x->posx == 0)
				ft_exitinerror(x);
			break ;
		}
	}
	if (x->zread < 0)
		ft_exitinerror(x);
}
