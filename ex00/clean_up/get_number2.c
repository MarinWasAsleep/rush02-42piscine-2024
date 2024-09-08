/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:55:51 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 19:04:19 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	skip_whitespaces(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	if (minus % 2 == 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (i);
}

int	get_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		len++;
	}
	return (len);
}

int	get_tab_size(int len)
{
	int	tab_size;

	if (len % 3 == 0)
		tab_size = len / 3;
	else
		tab_size = len / 3 + 1;
}
