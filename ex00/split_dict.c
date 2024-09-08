/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:37:22 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 18:51:07 by dgeinoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_dict_size(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == "\n")
			count++;
		i++;
	}
	return (count);
}

int	get_line_size(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] != "\n")
	{
		count++;
		i++;
	}
	return (count);
}

char	**split_dict(char *str)
{
	int		i;
	int		j;
	int		index;
	char	**dict;

	dict = (char **) malloc((get_dict_size(str) + 1) * sizeof(char *));
	if (dict == NULL)
		return (NULL);
	i = 0;
	index = 0;
	dict[index] = (char *) malloc((get_line_size + 1) * sizeof(char));
	if (dict[index] == NULL)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[i] != "\n")
			dict[index][j++] = str[i++];
		dict[index][j] = 0;
		index++;
	}
	dict[index] = NULL;
	return (dict);
}
