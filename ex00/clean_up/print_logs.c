/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:24:38 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 20:53:01 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	write_log_char(t_dict *dict, char c, int size)
{
	int		i;
	char	str[2];

	str[0] = c;
	str[1] = 0;
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].index, str) == 0)
		{
			write(1, dict[i].log, dict[i].log_size);
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
			return ;
		}
		i++;
	}
}

void	write_log_tens(t_dict *dict, char c, int size)
{
	int		i;
	char	str[3];

	str[0] = c;
	str[1] = '0';
	str[2] = 0;
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].index, str) == 0)
		{
			write(1, dict[i].log, dict[i].log_size);
			return ;
		}
		i++;
	}
}
