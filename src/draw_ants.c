/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:06:44 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/18 18:14:46 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

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
	ant->x_pos = ant->pos->draw_x + ROOM_W / 2 - LEM_W / 2;
	ant->y_pos = ant->pos->draw_y + ROOM_H / 2 - LEM_H / 2;
	ant->finished = 0;
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
			ft_printf("Found %d\n", ant->id);
			return (ant);
		}
		ant = ant->next;
	}
	return (create_ant(lem, ant_step));
}

void					remove_ant(t_list_of_ants **ants, t_list_of_ants *ant)
{
	t_list_of_ants *tmp;
	t_list_of_ants *start;

	tmp = NULL;
	if (*ants == ant)
	{
		tmp = *ants;
		*ants = (*ants)->next;
	}
	else
	{
		start = *ants;
		while (start->next)
		{
			if (start->next == ant)
			{
				tmp = start->next;
				start->next = start->next->next;
				break ;
			}
			start = start->next;
		}
	}
	free(tmp);
}

void	draw_ants(t_visual *vis)
{
	SDL_Rect		d_rect;
	t_list_of_ants	*ant;
	t_list_of_steps	*cr_step;
	int				i;

	if (vis->lem_data->ants == NULL)
		vis->lem_data->cur_step = vis->lem_data->steps;
	else if (vis->lem_data->cur_step == NULL)
		return ; // end moving properply
	cr_step = vis->lem_data->cur_step;
	i = 0;
	while (cr_step->step[i] != NULL)
	{
		ant = find_ant(vis->lem_data, cr_step->step[i]);
		update_x_y(ant, &d_rect);
		if (is_finished(ant, cr_step, vis->lem_data->nodes) && ant->pos == vis->lem_data->end)
		{
			remove_ant(&vis->lem_data->ants, ant);
			continue;
		}
		SDL_RenderCopy(vis->rend, vis->ant, NULL, &d_rect);
		i++;
	}
	print_ants(vis->lem_data);
	if (step_done(vis->lem_data->ants))
		vis->lem_data->cur_step = cr_step->next;
}
