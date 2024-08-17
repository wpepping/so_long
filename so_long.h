/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:37:44 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/17 19:26:18 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "minilibx/mlx.h"

# define TILE_WIDTH 64
# define TILE_HEIGHT 64
# define END_TILE_WIDTH 380
# define END_TILE_HEIGHT 160

# define EMPTY 48
# define WALL 49
# define COLLECTIBLE 67
# define MAPEXIT 69
# define PSTART 80
# define ESTART 78

# define ENEMY_MOVE_TIME 500

# define BULLET_SIZE 4
# define BULLET_MOVE_TIME 3

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_tilecount
{
	int	pstarts;
	int	exits;
	int	estarts;
}	t_tilecount;

typedef struct s_textures
{
	void	*background;
	void	*player;
	void	*player_dead;
	void	*wall[3];
	void	*weapon[3];
	void	*target;
	void	*enemy;
	void	*wasted;
	void	*youwin;
	void	*bullet;
}	t_textures;

typedef struct s_enemy
{
	long	movetime;
	t_coor	pos;
	t_coor	dir;
}	t_enemy;

typedef struct s_bullet
{
	long	movetime;
	t_coor	pospix;
	t_coor	postile;
	t_coor	dir;
}	t_bullet;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	char		**map;
	int			collectibles;
	int			collected;
	long		end_game;
	int			dummy;
	void		*end_game_graphic;
	t_enemy		enemy;
	t_bullet	bullet;
	t_textures	textures;
	t_coor		ppos;
	t_coor		pdir;
}	t_data;

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
void	free_map(char **map);
long	currtime(void);
void	copy_coor(t_coor *c1, t_coor *c2);
int		handle_close(t_data *data);
int		handle_input(int keycode, t_data *data);
int		handle_loop(t_data *data);
void	init_map(t_data *data);
void	move_player(t_data *data, int x, int y);
void	draw_tile(t_data *data, t_coor coor);
void	draw_bullet(t_data *data, t_bullet *bullet);
int		read_map(t_data *data, char *fname);
int		is_valid_map(t_data *data);
int		check_special_tiles(t_data *data);
void	init_textures(t_data *data);
void	clear_textures(t_data *data);
void	ft_putendl_fd(char *s, int fd);
void	get_color(t_data *data, int c[3], char *result);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
int		update_enemy(t_data *d, t_enemy *e);
int		update_bullet(t_data *d, t_bullet *b);
void	end_game(t_data *data, void *image);
void	shoot(t_data *data, t_bullet *bullet);
void	kill_enemy(t_data *d, t_enemy *e, t_bullet *b);
int		update_bullet(t_data *d, t_bullet *b);

#endif
