/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_graph.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:38:50 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/13 19:03:22 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_GRAPH_H
# define LEM_GRAPH_H
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include "SDL2/SDL_timer.h"
# include "ft_printf.h"
# include "libft.h"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define SCROLL_SPEED 100
# define SPEED 100
# define MAP_ROOMS_MODE			0
# define MAP_LINKS_MODE			1
# define MAP_ANTS_MODE			2
# define MAP_STEPS_MODE			3
# define GNL_READ_MODE			0
# define GNL_RETURN_COUNT_MODE	1
# define BFS_ORIGINAL			0
# define BFS_LESS_LINKS			1
# define DEFAULT				"\033[0m"
# define RED					"\033[1;31m"
# define GREEN					"\033[1;32m"
# define YELLOW					"\033[1;33m"
# define BLUE					"\033[1;34m"
# define PURPLE					"\033[1;35m"
# define CYAN					"\033[1;36m"
# define BG_RED					"\033[41m"
# define BG_DEFAULT				"\033[40m"


typedef struct	s_node
{
	char					*name;
	struct s_list_of_nodes	*links;
	int						x;
	int						y;
	struct s_node			*bfs_prev;
	int						bfs_used;
	int						bfs_in_queue;
	int						marked;
}				t_node;

typedef struct	s_list_of_nodes
{
	t_node					*node;
	struct s_list_of_nodes	*next;
}				t_list_of_nodes;
/*
** step - 2d array of positions of lem on current step
**	(e.g. step[0] == "L1-s2", step[1] == "L2-s1")
** next - link to next step
*/
typedef	struct	s_list_of_steps
{
	char					**step;
	struct s_list_of_steps	*next;
}				t_list_of_steps;

typedef struct	s_lem
{
	int						ants;
	t_list_of_nodes			*nodes;
	t_list_of_steps			*steps;
	t_node					*start;
	t_node					*end;
	int						flag_steps;
	int						flag_color;
	int						flag_paths;
}				t_lem;

typedef struct	s_visual
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*lem;
	SDL_Texture		*background;
	SDL_Texture		*room;
	t_lem			*lem_data;
}				t_visual;


int			init_sdl(t_visual *vis);
SDL_Texture	*load_tex(const char *file_name, t_visual *vis);
void		apply_surface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
/*
**Reading stuff
*/
void			read_map(t_lem *lem);
void			links_mode(char *line, t_lem *lem);
int				get_next_line_counter(int mode, int fd, char **line,
				t_lem *lem);
void			error(char *message, t_lem *lem);
t_node			*create_node(char *line, t_lem *lem);
int				push_node(t_list_of_nodes **list, t_node *node);
t_list_of_nodes	*create_list_of_nodes(t_node *first_node);
t_node			*pop_node(t_list_of_nodes **list);
void			remove_node(t_list_of_nodes **list, t_node *node);
int				node_in_path(t_list_of_nodes *path, t_node *node);
void			create_link(char *line, t_lem *lem);
void			rooms_mode(char *line, int *mode, t_lem *lem);
void			create_link(char *line, t_lem *lem);
void			steps_mode(char *line, t_lem *lem);

/*
** For debug purposes
*/
void	print_steps(t_lem *lem);
#endif
