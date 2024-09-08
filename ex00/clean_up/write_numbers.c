/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:35:02 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 20:47:25 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	retrieve_dict_size(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].log != NULL)
		i++;
	return (dict[i].log_size);
}

void	write_numbers(char **tab, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < retrieve_dict_size(dict))
	{
		block_analysis(tab[i], i, dict);
		i++;
	}
}
