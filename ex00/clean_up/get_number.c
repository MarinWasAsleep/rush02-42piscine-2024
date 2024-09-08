/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:46:58 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 20:06:08 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	skip_whitespaces(char *str);
int	get_len(char *str, int i);
int	get_tab_size(int len);

int	allocate_tabs(char **tab, int tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		tab[i] = (char *) malloc(4 * sizeof(char));
		if (tab[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}

int	fill_frst_block(char **tab, int len, char *str, int i)
{
	int	j;

	j = 0;
	while (j < 3 - (len % 3))
	{
		tab[0][j] = '0';
		j++;
	}
	while (j < 3)
	{
		tab[0][j] = str[i];
		i++;
		j++;
	}
	return (i);
}

void	fill_blocks(char **tab, char *str, int i, int len)
{
	int	index;
	int	j;

	if (len % 3 == 0)
		index = 1;
	else
		index = 0;
	while (str[i] >= '0' && str[i] <= '9' && index < get_tab_size(len))
	{
		j = 0;
		while (j < 3)
		{
			tab[index][j] = str[i];
			i++;
			j++;
		}
		tab[index][j] = 0;
		printf("Finished with tab[%d], ready to access tab[%d]\n", index, index + 1);
		index++;
	}
}

char	**get_number(char *str)
{
	int		i;
	int		len;
	int		tab_size;
	char	**tab;

	i = skip_whitespaces(str);
	if (i == -1)
		return (NULL);
	len = get_len(str, i);
	tab_size = get_tab_size(len);
	tab = (char **) malloc(tab_size * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	if (allocate_tabs(tab, tab_size) == 1)
		return (NULL);
	i -= len;
	if (len % 3 != 0)
		i = fill_frst_block(tab, len, str, i);
	fill_blocks(tab, str, i, len);
	return (tab);
}
