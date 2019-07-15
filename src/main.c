/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:36:15 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/15 20:21:16 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

static t_lem	*init_lem(void)
{
	t_lem *lem;

	lem = ft_memalloc(sizeof(t_lem));
	lem->nodes = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->flag_color = 0;
	lem->steps = NULL;
	return (lem);
}

static void	calc_draw_fact(t_visual *vis)
{
	int		room_numb;

	room_numb = ft_lstlen(vis->lem_data->nodes);
	calc_offset(vis, vis->lem_data->nodes);
	vis->scale = INIT_SCALE;
}

static void		init_all(t_visual *vis)
{
	ft_memset(vis, 0, sizeof(t_visual));
	vis->lem_data = init_lem();
	read_map(vis->lem_data);
	calc_draw_fact(vis);
	print_steps(vis->lem_data);
	init_sdl(vis);
}

int	main(void)
{
	t_visual	vis;
	SDL_Event	event;
	SDL_bool	is_running;

	init_all(&vis);
	is_running = SDL_TRUE;
	while (is_running)
	{
		SDL_SetRenderDrawColor(vis.rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(vis.rend);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				is_running = SDL_FALSE;
		}
		SDL_SetRenderDrawColor(vis.rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
		draw_connections(&vis);
		draw_rooms(&vis);
		SDL_RenderPresent(vis.rend);
	}
	SDL_DestroyWindow(vis.win);
	SDL_Quit();
}
