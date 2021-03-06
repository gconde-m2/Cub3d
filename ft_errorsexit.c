/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorsexit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 06:41:54 by gconde-m          #+#    #+#             */
/*   Updated: 2020/06/03 08:59:21 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cubexit(t_struct *x)
{
	int i;

	i = 0;
	free(x->used);
	free(x->distance);
	free(x->spritey);
	free(x->spritex);
	free(x->z_buffer);
	free(x->world_map);
	free(x->map_str_pos);
	while (i < x->map_height)
	{
		free(x->worldmap[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(x->mlx_ptr, x->texture_ptr[i]);
		x->texture_ptr[i] = NULL;
		i++;
	}
	exit(0);
}

void	checkerror(t_struct *x, char **s1, int argc)
{
	int fd;

	(void)x;
	if (argc == 3 && ft_memcmp(s1[2], "--save", 6) != 0)
		ft_exitinerror(x);
	if (argc == 3 && ft_memcmp(s1[2], "--save", 6) == 0)
		x->bmpflag = 1;
	else if (argc < 2)
		ft_exitinerror(x);
	else if (argc > 3)
		ft_exitinerror(x);
	if (ft_memcmp(ft_strrchr(s1[1], '.'), ".cub", 4) != 0)
		ft_exitinerror(x);
	if ((fd = open(s1[1], O_RDONLY)) < 0)
		ft_exitinerror(x);
}

void	ft_exitinerror(t_struct *x)
{
	(void)x;
	write(1, "error\n", 6);
	system("leaks CUB3D");
	exit(0);
}
