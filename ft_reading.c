/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:22:32 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/03 07:18:02 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_map(t_struct *x, char *line)
{
	char	*temp;
	char	*temp2;
	size_t	len;

	len = ft_strlen(line);
	x->map_width = x->map_width < (int)len ? len : x->map_width;
	if (len < 3)
		ft_exitinerror(x);
	temp = ft_strjoin(x->map_str, line);
	temp2 = ft_strjoin(temp, "\n");
	x->map_str = temp2;
	x->map_height++;
}

void	ft_readtextures(t_struct *x, char *line)
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
