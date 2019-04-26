/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:36:15 by dzboncak          #+#    #+#             */
/*   Updated: 2019/04/26 22:04:15 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

int main()
{
	t_visual	vis;
	SDL_Event	event;
	SDL_bool	is_running;

	init_sdl(&vis);
	/*At first we should read data and decide if we 
	can draw graph on screen
	
	read_data(&vis);
	*/
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
		apply_surface(0, 0, vis.background, vis.rend);
		SDL_SetRenderDrawColor(vis.rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(vis.rend, 10, 10, 50 ,50);
		SDL_RenderPresent(vis.rend);
	}
	SDL_DestroyWindow(vis.win);
	SDL_Quit();
}