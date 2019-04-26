/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:59:58 by dzboncak          #+#    #+#             */
/*   Updated: 2019/04/26 22:24:50 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

t_type		property(char *line)
{
	if (ft_strequ("##start", line))
		return (start);
	if (ft_strequ("##end", line))
		return (end);
	return (0);
}

int			read_data(t_lem_data *set)
{
	char	*line;
	int		hash_key;
	t_type	type;
	char	type_str;

	type = 0;
	type_str = 0;
	get_next_line(0, &line);
	set->input = ft_strdup_n(line);
	set->ant_num = ft_atoi(line);
	ft_strdel(&line);
	if (set->ant_num == 0)
		return (0);
	while (get_next_line(0, &line))
	{
		if (line == 0)
			break ;
		set->input = ft_strjoin_cs1(set->input, line);
		if (line[0] == '#')
			type = property(line);
		else if ((type_str = check_line(line)) == 0)
		{
			break ;
		}
		else if (type_str == 1)
		{
			hash_key = hash_f(line);
			if (hash_key >= set->size_anthil)
				anthil_incr(set, hash_key);
			anthil_write(set, line, &type, hash_key);
		}
		else if (!(write_connect(line, set)))
			break ;
		ft_strdel(&line);
	}
	if (line != 0)
		ft_strdel(&line);
	if (set->start == 0 || set->end == 0)
		return (0);
	return (1);
}