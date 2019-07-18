/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:31:00 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/18 18:24:00 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

/*
** If ant reached next node update its pos and next_pos
*/

void	update_ant_pos(t_list_of_ants *ant,
t_list_of_steps *cur, t_list_of_nodes *room)
{
	int	i;

	if (cur->next != NULL)
	{
		i = 0;
		cur = cur->next;
		ant->pos = ant->next_pos;
		while (cur->step[i] != NULL)
		{
			if (ant->id == get_id(cur->step[i]))
			{
				ant->next_pos = get_next_pos(cur->step[i], room);
				return ;
			}
			i++;
		}
	}
}

/*
** Checks if ant has reached its next_pos
*/

int		is_finished(t_list_of_ants *ant,
					t_list_of_steps *cur, t_list_of_nodes *room)
{
	int		x_diff;
	int		y_diff;
	int		diff;

	x_diff = (ant->next_pos->draw_x + ROOM_W / 2) - (ant->x_pos);
	x_diff *= x_diff;
	y_diff = (ant->next_pos->draw_y + ROOM_H / 2) - (ant->y_pos);
	y_diff *= y_diff;
	diff = sqrt(x_diff + y_diff);
	printf("diff is %d\n",diff);
	if ((int)sqrt(x_diff + y_diff) < (LEM_W))
	{
		update_ant_pos(ant, cur, room);
		return (ant->finished = 1);
	}
	return (ant->finished = 0);
}

/*
** Slightly move ant each frame
*/

void	update_x_y(t_list_of_ants *ant, SDL_Rect *rect)
{
	float	x_pos;
	float	y_pos;

	x_pos = ant->x_pos;
	y_pos = ant->y_pos;
	if (!ant->finished)
	{
		if ((ant->pos->draw_x + ROOM_W / 2) < (ant->next_pos->draw_x + ROOM_W / 2))
			x_pos += ANT_SPEED;
		else if ((ant->pos->draw_x + ROOM_W / 2) > (ant->next_pos->draw_x + ROOM_W / 2))
			x_pos -= ANT_SPEED;
		if ((ant->pos->draw_y + ROOM_H / 2) < (ant->next_pos->draw_y + ROOM_H / 2))
			y_pos += ANT_SPEED;
		else if ((ant->pos->draw_y + ROOM_H / 2) > (ant->next_pos->draw_y + ROOM_H / 2))
			y_pos -= ANT_SPEED;
	}
	ant->x_pos = x_pos;
	ant->y_pos = y_pos;
	rect->h = LEM_H;
	rect->w = LEM_W;
	rect->x = (int)x_pos;
	rect->y = (int)y_pos;
}

int		step_done(t_list_of_ants *ant)
{
	while (ant != NULL)
	{
		if (!ant->finished)
			return (0);
		ant = ant->next;
	}
	return (1);
}
