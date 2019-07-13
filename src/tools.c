/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:00:43 by dzboncak          #+#    #+#             */
/*   Updated: 2019/07/13 19:04:53 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

void	print_steps(t_lem *lem)
{
	t_list_of_steps *step;
	int				i;

	step = lem->steps;
	while (step != NULL)
	{
		i = 0;
		while (step->step[i] != NULL)
		{
			ft_printf(" %s ", step->step[i]);
			i++;
		}
		ft_putchar('\n');
		step = step->next;
	}
}
