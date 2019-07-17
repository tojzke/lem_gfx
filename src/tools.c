/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:00:43 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/17 20:45:18 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

int		ft_lstlen(t_list_of_nodes *start)
{
	int	len;

	len = 0;
	while (start != NULL)
	{
		start = start->next;
		len++;
	}
	return (len);
}

void	calc_offset(t_visual *vis, t_list_of_nodes *cur)
{
	int	x_min;
	int	x_max;
	int y_min;
	int y_max;

	x_max = FT_INT_MIN;
	x_min = FT_INT_MAX;
	y_min = FT_INT_MAX;
	y_max = FT_INT_MIN;
	while (cur != NULL)
	{
		x_max = (x_max < cur->node->x) ? cur->node->x : x_max;
		x_min = (x_min > cur->node->x) ? cur->node->x : x_min;
		y_max = (y_max < cur->node->y) ? cur->node->y : y_max;
		y_min = (y_min > cur->node->y) ? cur->node->y : y_min;
		cur = cur->next;
	}
	vis->x_off = (WIN_WIDTH - abs(x_max - x_min) + ROOM_W) / 2 - x_min;
	vis->y_off = (WIN_HEIGHT - abs(y_max - y_min) + ROOM_H) / 2 - y_min;
	if (WIN_WIDTH - abs(x_max - x_min) + ROOM_W < 0 ||
		WIN_HEIGHT - abs(y_max - y_min) + ROOM_H < 0)
		error("Map is too big", vis->lem_data);
	ft_printf("Set x_off:%d y_off:%d\n", vis->x_off, vis->y_off);
}
