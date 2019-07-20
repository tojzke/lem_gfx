/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surfaces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:05:29 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/20 18:53:02 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

void		apply_surface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend)
{
	SDL_Rect pos;

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}

void	put_text(SDL_Renderer *rend, int x, int y, char *text_msg)
{
	TTF_Font	*font;
	SDL_Color	font_color = {0, 0, 0};
	SDL_Surface	*surf_msg;
	SDL_Texture *message;
	SDL_Rect msg_rect;

	if (!(font = TTF_OpenFont("resources/Roboto-Medium.ttf", GUI_FONT_SIZE)))
		ft_printf("Can't open font\n");
	surf_msg = TTF_RenderText_Solid(font, text_msg, font_color);
	message = SDL_CreateTextureFromSurface(rend, surf_msg);
	msg_rect.x = x;
	msg_rect.y = y;
	msg_rect.h = GUI_H;
	msg_rect.w = GUI_W;
	SDL_RenderCopy(rend, message, NULL, &msg_rect);
	SDL_FreeSurface(surf_msg);
	SDL_DestroyTexture(message);
}