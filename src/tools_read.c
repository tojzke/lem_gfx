/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 22:37:06 by bkiehn            #+#    #+#             */
/*   Updated: 2019/04/26 22:23:33 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

int			hash_f(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (str[i + 1] != 0)	
				return (str[i] + str[i + 1] + str[i + 2]);
			else
				return (str[i] + str[i + 1]);
		}
		i++;
	}
	return (ft_atoi(str));
}

void		anthil_incr(t_lem_data *set, int key)
{
	t_vertex **tmp;
	int		j;
	int		i;

	i = set->size_anthil;
	while (set->size_anthil <= key)
		set->size_anthil += ANTHIL_INCR;
	tmp = (t_vertex**)ft_memalloc(sizeof(t_vertex*) * set->size_anthil);
	j = 0;
	while (j < i)
	{
		tmp[j] = set->anthil[j];
		j++;
	}
	if (set->anthil != 0)
	 	free(set->anthil);
	set->anthil = tmp;
}

void		anthil_write(t_lem_data *set, char *name, t_type *type, int key)
{
	t_vertex	*tmp;
	t_vertex	*tmppred;

	tmp = set->anthil[key];
	if (tmp == 0)
	{
		tmp = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		set->anthil[key] = tmp;
	}
	else
	{
		while (tmp != 0)
		{
			tmppred = tmp;
			tmp = tmp->next;
		}
		tmp = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		tmppred->next = tmp;
	}
	tmp->name = ft_strdup(name);	
	tmp->type = *type;
	if (*type == start)
		set->start = tmp;
	else if (*type == end)
		set->end = tmp;
	*type = 0;
}

char		*ft_strjoin_cs1(char *s1, char *s2)
{
	size_t	i;
	char	*a;
	size_t	j;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	while (s1[i] != 0)
		a[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		a[j++] = s2[i++];
	a[j] = '\n';
	a[j + 1] = 0;
	free(s1);
	return (a);
}

char	*ft_strdup_n(const char *s1)
{
	size_t	i;
	size_t	n;
	char	*cop;

	if (s1 == 0)
		return (0);
	n = ft_strlen(s1);
	i = 0;
	if ((cop = (char*)malloc(sizeof(char) * (n + 2))) == NULL)
		return (NULL);
	cop[n] = '\n';
	cop[n + 1] = 0;
	while (n--)
	{
		cop[i] = s1[i];
		i++;
	}
	return (cop);
}
