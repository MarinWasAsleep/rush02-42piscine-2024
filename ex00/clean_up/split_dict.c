/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:30:25 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 22:16:23 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dict	*fill_dict(char *str)
{
	int	i;
	int	entry;

	i = 0;
	entry = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			dict[entry] = get_index(dict[entry], str, i);
			i += dict[entry].index_size;
		}
		else if (is_alpha(str[i]) == 0)
		{
			dict[entry] = get_log(dict[entry], str, i);
			i += dict[entry].log_size;
		}
		else if
		else
			i++;
	}
}

t_dict	*split_dict(char *str)
{
	t_dict	*dict;

	dict = (t_dict *) malloc(get_dict_size(str) * sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	dict = fill_dict(str);
}
