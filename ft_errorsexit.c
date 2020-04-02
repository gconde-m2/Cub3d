#include "cub3d.h"

void	cubexit(t_struct *x)
{
	free(x->used);
	free(x->distance);
	free(x->spritey);
	free(x->spritex);
	free(x->z_buffer);
	free(x->world_map);
	system("leaks CUB3D");
	exit(0);
}

void	checkerror(t_struct *x, char **s1, int argc)
{
	int fd;
	(void)x;
	if (argc == 3 && ft_memcmp(s1[2], "--save", 6) != 0)
		ft_exitinerror(x);
	if (argc == 3 && ft_memcmp(s1[2], "--save", 6) == 0)
        x->bmpflag= 1;
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
	ft_printf("está mal,intentalo de nuevo inutil");
	system("leaks CUB3D");
	exit(0);

}