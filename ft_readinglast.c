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

static void	check_and_set_values(t_struct *x, int i, int j)
{
	if ((*x->map_str < '0' || *x->map_str > '2') &&
	(*x->map_str != 'N' && *x->map_str != 'S' &&
	*x->map_str != 'E' && *x->map_str != 'W' && *x->map_str != ' ' &&
	*x->map_str != '\n'))
		ft_exitinerror(x);
	if (*x->map_str == '2')
		x->num++;
	else
	{
		if (ft_isalpha(*x->map_str))
		{
			if (x->posx != 0)
				ft_exitinerror(x);
			x->posx = i + 0.5;
			x->posy = j + 0.5;
			x->dir = *x->map_str;
			*x->map_str = '0';
		}
		if (*x->map_str == ' ')
			*x->map_str = '3';
	}
}

static void	check_and_set_map(t_struct *x)
{
	int i;

	i = 0;
	if (!(x->worldmap = malloc(sizeof(int*) * x->map_height)))
		ft_exitinerror(x);
	ft_bzero(x->worldmap, sizeof(int*));
	while (i < x->map_height)
	{
		if (!(x->worldmap[i] = malloc(sizeof(int) * x->map_width)))
			ft_exitinerror(x);
		i++;
	}
}

void		ft_check_map(t_struct *x)
{
	int	i;
	int	j;

	i = 0;
	x->map_str_pos = x->map_str;
	while (i < x->map_height)
	{
		j = 0;
		while (j < x->map_width)
		{
			check_and_set_values(x, i, j);
			if (*x->map_str == '\n')
				x->worldmap[i][j] = 3;
			else
				x->worldmap[i][j] = *x->map_str - '0';
			if (*x->map_str != '\n')
				x->map_str++;
			j++;
		}
		x->map_str++;
		i++;
	}
	ft_validate_map(x);
}

int			ft_validate_map_2(t_struct *x, int row, int col)
{
	char	c;
	int		ok;

	if (row < 0 || col < 0 || row >= x->map_height || col >= x->map_width)
		return (1);
	c = x->worldmap[row][col];
	if (c == 3)
		return (1);
	else if (c == 4 || c == 1 || c == 5)
		return (0);
	if (x->worldmap[row][col] == 0)
		x->worldmap[row][col] = 4;
	else
		x->worldmap[row][col] = 5;
	ok = ft_validate_map_2(x, row, col - 1);
	ok = ok == 0 ? ft_validate_map_2(x, row, col + 1) : ok;
	ok = ok == 0 ? ft_validate_map_2(x, row - 1, col) : ok;
	ok = ok == 0 ? ft_validate_map_2(x, row + 1, col) : ok;
	return (ok);
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
		free(line);
		if (x->zread == 0)
		{
			if (x->map_height < 3 || x->map_width < 3)
				ft_exitinerror(x);
			check_and_set_map(x);
			ft_check_map(x);
			break ;
		}
	}
	if (x->zread < 0)
		ft_exitinerror(x);
}
