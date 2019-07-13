/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:29:35 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/13 18:59:11 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

t_list_of_steps	*create_step_node(char *line)
{
	t_list_of_steps *node;

	node = (t_list_of_steps*)ft_memalloc(sizeof(t_list_of_steps));
	node->step = ft_strsplit(line,' ');
	node->next = NULL;
	return	(node);
}

void	steps_mode(char *line, t_lem *lem)
{
	t_list_of_steps	*steps;

	steps = lem->steps;
	if (steps == NULL)
		lem->steps = create_step_node(line);
	else
	{
		while (steps->next != NULL)
			steps = steps->next;
		steps->next = create_step_node(line);
	}
}