/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:31:00 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/18 19:37:54 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

void	calc_speed(t_list_of_ants *ant, float *x_vel, float *y_vel)
{
	int		x_diff;
	int		y_diff;

	x_diff = (int)abs(ant->next_pos->draw_x - ant->pos->draw_x);
	y_diff = (int)abs(ant->next_pos->draw_y - ant->pos->draw_y);
	if (x_diff > y_diff)
	{
		*y_vel = ANT_SPEED / 60.0;
		if (y_diff != 0)
			*x_vel = ANT_SPEED * ((float)x_diff / (float)y_diff) / 60;
		else
			*x_vel = ANT_SPEED / 60.0;
	}
	else
	{
		*x_vel = ANT_SPEED / 60.0;
		if (x_diff != 0)
			*y_vel = ANT_SPEED * ((float)y_diff / (float)x_diff) / 60;
		else
			*y_vel = ANT_SPEED / 60.0;
	}
}

/*
** Slightly move ant each frame
*/

void	update_x_y(t_list_of_ants *ant, SDL_Rect *rect)
{
	float	x_pos;
	float	y_pos;
	float	x_vel;
	float	y_vel;

	x_pos = ant->x_pos;
	y_pos = ant->y_pos;
	float tmp_speed = ANT_SPEED / 60.0;
	if (!ant->finished)
	{
		calc_speed(ant, &x_vel, &y_vel);
		if ((ant->pos->draw_x + ROOM_W / 2) < (ant->next_pos->draw_x + ROOM_W / 2))
			x_pos += x_vel;
		else if ((ant->pos->draw_x + ROOM_W / 2) > (ant->next_pos->draw_x + ROOM_W / 2))
			x_pos -= x_vel;
		if ((ant->pos->draw_y + ROOM_H / 2) < (ant->next_pos->draw_y + ROOM_H / 2))
			y_pos += y_vel;
		else if ((ant->pos->draw_y + ROOM_H / 2) > (ant->next_pos->draw_y + ROOM_H / 2))
			y_pos -= y_vel;
	}
	ant->x_pos = x_pos;
	ant->y_pos = y_pos;
	rect->h = LEM_H;
	rect->w = LEM_W;
	rect->x = (int)x_pos;
	rect->y = (int)y_pos;
}

