/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:37:44 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/11 19:17:18 by wpepping         ###   ########.fr       */
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
	void	*weapon1;
	void	*weapon2;
	void	*weapon3;
	void	*target;
	void	*enemy;
	void	*wasted;
	void	*youwin;
}	t_textures;

typedef struct s_enemy
{
	long	movetime;
	t_coor	pos;
	int		dir_x;
	int		dir_y;
}	t_enemy;

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
	t_enemy		enemy;
	t_textures	textures;
	t_coor		ppos;
}	t_data;

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
void	free_map(char **map);
long	currtime(void);
int		handle_close(t_data *data);
int		handle_input(int keycode, t_data *data);
int		handle_loop(void);
void	init_map(t_data *data);
void	move_player(t_data *data, int x, int y);
void	draw_tile(t_data *data, t_coor coor);
int		read_map(t_data *data, char *fname);
int		is_valid_map(t_data *data);
int		check_special_tiles(t_data *data);
void	init_textures(t_data *data);
void	clear_textures(t_data *data);
void	ft_putendl_fd(char *s, int fd);
char	*get_next_line(int fd);
int		update_enemy(t_data *data);
void	end_game(t_data *data, void *image);

#endif
