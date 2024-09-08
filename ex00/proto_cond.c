/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:59:44 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 18:13:54 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	printf("Comparing %s and %s\n", s1, s2);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			printf("Difference found inside string\n");
			return (s1[i] - s2[i]);
		}
		i++;
	}
	printf("No difference found inside string\n");
	return (s1[i] - s2[i]);
}

void	write_log_char(t_dict *dict, char c, int size)
{
	int	i;
	char str[2];

	str[0] = c;
	str[1] = 0;
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].index, str) == 0)
		{
			write(1, dict[i].log, dict[i].log_size);
			write(1, " ", 1);
			return ;
		}
		i++;
	}
}

void	write_log_str(t_dict *dict, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].index, str) == 0)
		{
			write(1, dict[i].log, dict[i].log_size);
			write(1, " ", 1);
			return ;
		}
		i++;
	}
}

void	write_log_tens(t_dict *dict, char c, int size)
{
	int	i;
	char str[3];

	str[0] = c;
	str[1] = '0';
	str[2] = 0;
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].index, str) == 0)
		{
			write(1, dict[i].log, dict[i].log_size);
			write(1, " ", 1);
			return ;
		}
		i++;
	}
}

int	get_dict_size2(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].log != NULL)
		i++;
	return (dict[i].log_size);
}

void	print_logs(t_dict *dict, char **tab, int nb_of_elements_in_tab)
{
	int	i;
	int	j;
	int	dict_size;

	dict_size = get_dict_size2(dict);
	i = 0;
	while (i < nb_of_elements_in_tab)
	{
		if (tab[i][0] != 0)
		{
			write_log_char(dict, tab[i][0], dict_size);
			write_log_str(dict, "100", dict_size);
		}
		if (tab[i][1] != 0)
		{
			write_log_tens(dict, tab[i][1], dict_size);
		}
		if (tab[i][2] != 0)
		{
			write_log_char(dict, tab[i][2], dict_size);
		}
		i--;
	}
}
