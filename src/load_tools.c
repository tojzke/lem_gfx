/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:28:52 by dzboncak          #+#    #+#             */
/*   Updated: 2019/04/26 21:18:38 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

SDL_Texture *load_tex(const char *file_name, t_visual *vis)
{
	SDL_Surface	*loaded_image;
	SDL_Texture	*tex;

	loaded_image = IMG_Load(file_name);
	if (loaded_image != NULL)
	{
		tex = SDL_CreateTextureFromSurface(vis->rend,loaded_image);
		SDL_FreeSurface(loaded_image);
	}
	else
	{
		ft_printf("Can't create texture %s\n",SDL_GetError());
	}
	return (tex);
}