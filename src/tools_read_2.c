/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_read_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:32:42 by bkiehn            #+#    #+#             */
/*   Updated: 2019/04/26 22:21:09 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

int			add_adj_vertex(t_vertex *room, int i, t_vertex *vertex)
{
	t_vertex	**tmp;
	int			j;

	j = 0;
	tmp = (t_vertex**)ft_memalloc(sizeof(t_vertex*) * (i + 1));
	while(j < i)
	{
		if (room->adjacent[j] == vertex)
			return (0);
		tmp[j] = room->adjacent[j];
		j++;
	}
	tmp[i] = vertex;
	free(room->adjacent);
	room->adjacent = tmp;
	return (1);
}

int			write_adjacet(t_vertex *tmp, t_vertex *tmp2)
{
	if (tmp == 0 || tmp2 == 0)
		return (0);
	if (tmp->number_adj == 0)
	{
		tmp->adjacent = (t_vertex**)ft_memalloc(sizeof(t_vertex*));
		tmp->adjacent[0] = tmp2;
	}
	else
		add_adj_vertex(tmp, tmp->number_adj, tmp2);
	tmp->number_adj++;
	if (tmp2->number_adj == 0)
	{
		tmp2->adjacent = (t_vertex**)ft_memalloc(sizeof(t_vertex*));
		tmp2->adjacent[0] = tmp; 
	}
	else
		if (!(add_adj_vertex(tmp2, tmp2->number_adj, tmp)))
			return (0);
	tmp2->number_adj++;
	return (1);
}

int			write_connect(char *first, t_lem_data *set)
{
	int			i;
	char		*second;
	t_vertex	*vertices[2];
	int			key_hash;
	int			key2_hash;

	i = 0;
	while (first[i] != 0)
	{
		if (first[i] == '-')
		{
			first[i] = 0;
			second = first + i + 1;
		}
		i++;
	}
	key_hash = hash_f(first);
	key2_hash = hash_f(second);
	if (key_hash >= set->size_anthil || key2_hash >= set->size_anthil)
		return (0);
	vertices[0] = set->anthil[key_hash];
	vertices[1] = set->anthil[key2_hash];
	while (vertices[0] != 0)
	{
		if (ft_strequ(vertices[0]->name, first))
			break ;
		vertices[0] = vertices[0]->next;
	}
	while (vertices[1] != 0)
	{
		if (ft_strequ(vertices[1]->name, second))
			break ;
		vertices[1] = vertices[1]->next;
	}
	return (write_adjacet(vertices[0], vertices[1]));
}
