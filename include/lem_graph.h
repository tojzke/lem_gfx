/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_graph.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:38:50 by dzboncak          #+#    #+#             */
/*   Updated: 2019/04/26 22:26:55 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_GRAPH_H
# define LEM_GRAPH_H
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include "SDL2/SDL_timer.h"
# include "ft_printf.h"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define SCROLL_SPEED 100
# define SPEED 100
# define ANTHIL_INCR 10

typedef enum		e_type
{
	start = 1, end
}					t_type;

typedef	struct	s_lem_data
{
	char			*input;
	struct s_vertex	*start;
	struct s_vertex *end;
	struct s_vertex **anthil;
	int				size_anthil;
	int				ant_num;
}				t_lem_data;

typedef struct	s_visual
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*lem;
	SDL_Texture		*background;
	SDL_Texture		*room;
	t_lem_data		*lem_data;
}				t_visual;

typedef struct	s_vertex
{
	int				x;
	int				y;
	char			*name;
	struct s_vertex **adjacent;
	struct s_vertex *next;
	int				number_adj;
	t_type			type;
}				t_vertex;

int				init_sdl(t_visual *vis);
SDL_Texture *load_tex(const char *file_name, t_visual *vis);
void		apply_surface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);

/*
Reading stuff
*/
int			add_adj_vertex(t_vertex *room, int i, t_vertex *vertex);
int			write_adjacet(t_vertex *tmp, t_vertex *tmp2);
int			write_connect(char *ferst, t_lem_data *set);
int			hash_f(char *str);
void		anthil_incr(t_lem_data *set, int key);
void		anthil_write(t_lem_data *set, char *name, t_type *type, int key);
char		*ft_strjoin_cs1(char *s1, char *s2);
char		*ft_strdup_n(const char *s1);
int			check_line(char *line);
int			check_vertex(char *str);
int			check_connect(char *str);

#endif
