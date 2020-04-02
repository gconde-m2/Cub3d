/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 08:25:28 by gconde-m          #+#    #+#             */
/*   Updated: 2020/03/06 11:27:03 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
#define FT_CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "getnextline/get_next_line.h"
#define screenWidth 1280
#define screenHeight 720
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define UDIV 0.6
# define VDIV 0.6
# define VMOVE 0
# define SPRITE_TEXT 4
# define BITMAP_SIZE 54
# define BITS_PER_PIXEL 24
# define DPI 2835
# define OFFSET 14
# define DIB_HEADER 40


typedef struct	s_struct
{
	//mlx y funciones
    int **worldMap;
	void *mlx_ptr;
	void *win_ptr;
	void *image;	
	int *data;
	int reswidth;
	int resheight;
	//raycasting/jugador/muros
  	double posx;
	double posy;  
  	double dirx;
	double diry;   
  	double planex; 
	double planey; 
  	double time;
  	double oldtime;
	double camerax;
	double raydirx;
	double raydiry;
	int mapx;
	int mapy;
	int x;
	int h;
	int w;
	int n;
    int *dataI;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	int stepx;
	int stepy;
	int hit;
	int side;
	int drawstart;
	int drawend;
	int lineheight;
	unsigned int color;
	int bits;
	int endian;
	int size_line;
	double dy;
	double dx;
    //teclas
	int kd;
	int ka;
    int key;
    int kw;
    int karrowright;
    int ks;
    int karrowleft;
	double rotspeed;
    double speed;
    double old_dirx;
    double old_diry;
    double old_planex;
    double old_planey;
    //texturas
	int wp;
	int hp;
	unsigned int buffer[480][640];
	//int screenHeight;
	//int screenWidth;
	int	texwidth;
	int texheight;
	int i;
	int *texture[11];
	double wallx;
	int texnum;
	int textx;
	double step;
	double texpos;
	int texty;
	void	*view_ptr;
	void	*texture_ptr;
    //floor and ceiling
	float raydirx0 ;
      float raydiry0;
      float raydirx1 ;
      float raydiry1;
      int p ;
      float posz;
      float rowdistance ;
      float floorstepx ;
      float floorstepy;
      float floorx;
	  float floory;
	  int cellx;
        int celly;
        int tx ;
        int ty ;
		int floortexture ;
        int ceilingtexture;
		int y;
		int z;
		int zread;
	//spritesq
	//int sprites[2];
	double 		*z_buffer;
	double 		*spritedistance;
	int 		*spriteorder;
	double 		*spritex;
	double 		*spritey;
	int			num;
	int			width;
	int			*used;
	int			height;
	int			screen_x;
	int			v_move_screen;
	int			texture_x;
	int			texture_y;
	int			draw_end_x;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_start_y;
	double		pos_x;
	double		pos_y;
	double		inv_det;
	double		*distance;
	double		transform_x;
	double		transform_y;

	//lectura
	int floor_red;
	int floor_blue;
	int floor_green;
	int cealing_red;
	int cealing_blue;
	int	cealing_green;
	int map_height;
	int map_width;
	char *map_str;
	int **world_map;
	char dir;
	//bmp
	int bmpflag;
	

}				t_struct;

void	cub3d(int argc, char **argv);
void    ft_tozero(t_struct *x);
void    ft_calculo(t_struct *x);
void    ft_draw(t_struct *x);
void    ft_color(t_struct *x);
void    ft_calculotwo(t_struct *x);
void    ft_raycasting(t_struct *x);
int     key_pressed(int key, t_struct *x);
int     key_released(int key, t_struct *x);
int     move_draw(t_struct *x);
int     main(int argc, char **argv);
void 	move_left_right(t_struct *x);
void 	move_up_down(t_struct *x);
void	ft_sprites(t_struct *x);
void    ft_floorcasting( t_struct *x);
void    ft_cellcalc(t_struct *x);
void    ft_floorcalc(t_struct *x);
void 	ft_texturesup(t_struct *x);
void    ft_befdraw(t_struct *x);
int		sprites_init(t_struct *x);
void	get_x_y(t_struct *x);
int		get_index(t_struct *x);
void	sprites_casting(t_struct *x);
void	calculate_distances(t_struct *x);
void	set_start_end(t_struct *x);
void	draw_sprite(t_struct *x, int stripe);
void	rotate(t_struct *x);
void	cubexit(t_struct *x);
void	checkerror(t_struct *x, char **s1, int aargc);
void	reading_all(t_struct *x, char *s1);
void	ft_readtextures(t_struct *x,char *line);
void	ft_check(t_struct *x,char *line);
void	ft_read_map(t_struct *x, char *line);
void	ft_exitinerror(t_struct *x);
void 	ft_readres(t_struct *x, char *line);
void	check_cealing_color(t_struct *x, char *line);
void	check_floor_color(t_struct *x, char *line);
void	readtextures_2(t_struct *x, char *line, int h, int w);
void	ft_texturehelpingread(t_struct *x, char *line, int i);
void	makebmp(t_struct *x);
#endif

