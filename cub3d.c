/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <gconde-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 08:47:59 by gconde-m          #+#    #+#             */
/*   Updated: 2020/07/02 11:04:18 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calculo(t_struct *x)
{
	x->datai = x->data;
	x->x = 0;
	x->i = 0;
	while (x->x < x->w)
	{
		x->camerax = 2 * x->x / (double)x->w - 1;
		x->raydirx = x->dirx + x->planex * x->camerax;
		x->raydiry = x->diry + x->planey * x->camerax;
		x->mapx = (int)x->posx;
		x->mapy = (int)x->posy;
		x->deltadistx = fabs(1 / x->raydirx);
		x->deltadisty = fabs(1 / x->raydiry);
		x->hit = 0;
		ft_raycasting(x);
		ft_calculotwo(x);
		ft_color(x);
		ft_draw(x);
		x->z_buffer[x->x] = x->perpwalldist;
		x->x++;
		x->datai++;
		x->n = 0;
	}
	sprites_casting(x);
}

int		main(int argc, char **argv)
{
	t_struct x;

	ft_bzero(&x, sizeof(t_struct));
	ft_tozero(&x);
	(void)argc;
	x.mlx_ptr = mlx_init();
	checkerror(&x, argv, argc);
	reading_all(&x, argv[1]);
	sprites_init(&x);
	x.win_ptr = mlx_new_window(x.mlx_ptr, x.w, x.h, "raycaster");
	x.image = mlx_new_image(x.mlx_ptr, x.w, x.h);
	x.data = (int *)mlx_get_data_addr(x.image, &x.bits,
						&x.size_line, &x.endian);
	mlx_hook(x.win_ptr, 2, 1, key_pressed, &x);
	mlx_hook(x.win_ptr, 3, 2, key_released, &x);
	mlx_loop_hook(x.mlx_ptr, move_draw, &x);
	mlx_loop(x.mlx_ptr);
	return (0);
}
