/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:06:44 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/17 21:13:17 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

static void	calc_ant_x_y(t_visual *vis, t_list_of_ants *ant, SDL_Rect *rect)
{
	int		calc_x;
	int		calc_y;

	calc_x = ((ant->next_pos->draw_x - LEM_W / 2 + ROOM_W / 2) -
	(ant->pos->draw_x - LEM_W / 2 + ROOM_W / 2)) * ant->percent;
	calc_y = ((ant->next_pos->draw_y - LEM_H / 2 + ROOM_H / 2) -
	(ant->pos->draw_y - LEM_H / 2 + ROOM_H / 2)) * ant->percent;
	rect->x = vis->lem_data->start->draw_x - LEM_W / 2 + ROOM_W / 2;
	rect->y = vis->lem_data->start->draw_y - LEM_H / 2 + ROOM_H / 2;
	rect->h = LEM_H;
	rect->w = LEM_W;
}

int		get_id(char *str)
{
	str = ft_strchr(str, 'L') + 1;
	return (ft_atoi(str));
}

t_node	*get_next_pos(char *str, t_list_of_nodes *room)
{
	str = ft_strchr(str, '-') + 1;
	while (room != NULL)
	{
		if (ft_strequ(str, room->node->name))
			return (room->node);
		room = room->next;
	}
	return (NULL);
}

t_list_of_ants	*create_ant(t_lem *lem, char *ant_step)
{
	t_list_of_ants	*ant;
	t_list_of_ants	*tmp;

	ant = ft_memalloc(sizeof(t_list_of_ants));
	ant->id = get_id(ant_step);
	ant->pos = lem->start;
	ant->next_pos = get_next_pos(ant_step, lem->nodes);
	ant->next = NULL;
	if (lem->ants == NULL)
		return (lem->ants = ant);
	tmp = lem->ants;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp->next = ant);
}

t_list_of_ants	*find_ant(t_lem *lem, char *ant_step)
{
	t_list_of_ants *ant;

	ant = lem->ants;
	while (ant != NULL)
	{
		if (ant->id == get_id(ant_step))
		{
			ft_printf("Found %d\n",ant->id);
			return (ant);
		}
		ant = ant->next;
	}
	return (create_ant(lem, ant_step));
}

void	draw_ants(t_visual *vis)
{
	SDL_Rect		d_rect;
	t_list_of_ants	*ant;
	t_list_of_steps	*cr_step;
	int				i;

	i = 0;
	if (vis->lem_data->ants == NULL)
		vis->lem_data->cur_step = vis->lem_data->steps;
	else if (vis->lem_data->cur_step == NULL)
		exit(0);
	cr_step = vis->lem_data->cur_step;
	while (cr_step->step[i] != NULL)
	{
		ant = find_ant(vis->lem_data, cr_step->step[i]);
		//calc_percent(ant)
		//calc_ant_x_y(ant)
		// SDL_RenderCopy(vis->rend, vis->ant, NULL, &d_rect);
		i++;
	}
	print_ants(vis->lem_data);
	vis->lem_data->cur_step = cr_step->next;
}
