/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:07:23 by bkiehn            #+#    #+#             */
/*   Updated: 2019/04/26 22:26:50 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_graph.h"

int			check_connect(char *str)
{
	int		i;
	char	f;
	char	fi;

	i = 0;
	f = 0;
	fi = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ' || (i == 0 && str[i] == '-'))
			return (0);
		if (str[i] == '-')
		{
			fi = i + 1;
			f++;
		}
		i++;
	}
	if (f == 1 && fi != i)
		return (2);
	return (0);
}

int			check_vertex(char *str)
{
	int i;
	int	f;
	int	fi;

	i = 0;
	f = 0;
	fi = 0;
	while (str[i] != 0)
	{
		if ((str[i] == ' ' && i == 0) || ((str[i] < 48 || str[i] > 57) && str[i] != ' '))
			return (0);
		if (str[i] == ' ')
		{
			fi = i + 1;
			f++;
		}
		i++;
	}
	if (f == 1 && fi != i)
		return (1);
	return (0);
}

int			check_line(char *line)
{
	int		i;

	i = 0;
	if (*line == 'L')
		return (0);
	while (line[i] != 0)
	{
		if (line[i] == '-')
			return (check_connect(line));
		if (line[i] == ' ')
		{
			line[i] = 0;
			return (check_vertex(line + i + 1));
		}
		i++;
	}
	return (0);
}
