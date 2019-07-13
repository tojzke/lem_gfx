/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:36:15 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/13 19:00:34 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

void	draw_room(t_visual *vis, int x, int y)
{
	SDL_Rect rect;
	SDL_Surface *s;
	
	rect.x = x;
	rect.y = y;
	rect.h = 25;
	rect.w = 25;
	SDL_SetRenderDrawColor(vis->rend, 255, 255, 255, 255);
	SDL_RenderFillRect(vis->rend, &rect);
}

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

int main()
{
	t_visual	vis;
	SDL_Event	event;
	SDL_bool	is_running;

	vis.lem_data = init_lem();
	read_map(vis.lem_data);
	print_steps(vis.lem_data);
	init_sdl(&vis);
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
		// apply_surface(0, 0, vis.background, vis.rend);
		SDL_SetRenderDrawColor(vis.rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
		draw_room(&vis, 60, 60);
		// draw_rooms(&vis);
		SDL_RenderPresent(vis.rend);
	}
	SDL_DestroyWindow(vis.win);
	SDL_Quit();
}