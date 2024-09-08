/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:00:12 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 12:46:06 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// si func = 1 --> get_log_size
// si func = 0 --> get_index_size
int	get_size(char *str, int i, int func)
{
	int	count;

	count = 1;
	if (func == 0)
	{
		while (str[i] != ':')
		{
			i++;
			count++;
		}
		return (count);
	}
	else if (func == 1)
	{
		while (is_alpha(str[i]) == 1)
		{
			i++;
			count++;
		}
		return (count);
	}
	return (0);
}

void	print_results(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].log != NULL)
	{
		printf("Entry [%d] has index \"%s\" of size %d and log \"%s\" of size %d\n", i, dict[i].index, dict[i].index_size, dict[i].log, dict[i].log_size);
		i++;
	}
}

t_dict	get_index(t_dict entry, char *str, int i)
{
	int	j;

	entry.index_size = get_size(str, i, 0);
	entry.index = (char *) malloc(entry.index_size * sizeof(char));
	j = 0;
	while (j + 1 < entry.index_size)
	{
		entry.index[j] = str[i];
		i++;
		j++;
	}
	entry.index[j] = 0;
	return (entry);
}

t_dict	get_log(t_dict entry, char *str, int i)
{
	int	j;

	entry.log_size = get_size(str, i, 1);
	entry.log = (char *) malloc(entry.log_size * sizeof(char));
	j = 0;
	while (j + 1 < entry.log_size)
	{
		entry.log[j] = str[i];
		i++;
		j++;
	}
	entry.log[j] = 0;
	return (entry);
}


int	get_dict_size(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

t_dict	*split_dict(char *str)
{
	int		i;
	int		j;
	int		entry;
	t_dict	*dict;

	dict = (t_dict *) malloc(get_dict_size(str) * sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	i = 0;
	entry = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			dict[entry] = get_index(dict[entry], str, i);
			i += ft_strlen(dict[entry].index);
		}
		else if (is_alpha(str[i]))
		{
			dict[entry] = get_log(dict[entry], str, i);
			i += ft_strlen(dict[entry].log);
		}
		else if (str[i] == '\n' && str[i + 1] != '\n')
		{
			entry++;
			i++;
		}
		else
			i++;
	}
	dict[entry].log = NULL;
	print_results(dict);
	entry = 0;
	while (dict[entry].log != NULL)
	{
		free(dict[entry].index);
		free(dict[entry].log);
		entry++;
	}
	free(dict);
	return (dict);
}
