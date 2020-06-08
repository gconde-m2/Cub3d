/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:31:48 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/01 13:32:23 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		header(int fd, int file_size)
{
	int aux;

	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	aux = 0;
	write(fd, &aux, 4);
	aux = OFFSET + DIB_HEADER;
	write(fd, &aux, 4);
}

static void		cabecera(t_struct *x, int fd)
{
	int file_size;
	int aux;

	aux = x->w * x->h;
	file_size = (4 + BITMAP_SIZE) * aux;
	header(fd, file_size);
	aux = DIB_HEADER;
	write(fd, &aux, 4);
	write(fd, &x->w, 4);
	write(fd, &x->h, 4);
	aux = 1;
	write(fd, &aux, 2);
	aux = 32;
	write(fd, &aux, 2);
	aux = 0;
	write(fd, &aux, 4);
	write(fd, &file_size, 4);
	aux = DPI;
	write(fd, &aux, 4);
	write(fd, &aux, 4);
	aux = 0;
	write(fd, &aux, 8);
}

void			makebmp(t_struct *x)
{
	int		fd;
	int		h;
	int		w;
	int		aux;

	if ((fd = open("Cube3d.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
		ft_exitinerror(x);
	else
	{
		cabecera(x, fd);
		h = -1;
		while (++h < x->h)
		{
			w = -1;
			while (++w < x->w)
			{
				aux = *(x->dataI + (h * x->w + w));
				write(fd, &aux, 4);
			}
		}
	}
	close(fd);
	cubexit(x);
}
