/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:12 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 22:54:57 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int		i;
	char	*number;
	char	*dict_str;
	char	*path;
	char	**tab;
	t_dict	*dict;

	if (ac != 2 && ac != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (ac == 2)
	{
		path = "numbers.dict";
		number = av[1];
	}
	else if (ac == 3)
	{
		path = av[1];
		number = av[2];
	}
	tab = get_number(number);
	if (tab == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	dict_str = ft_parse_dict(path);
	if (dict_str == NULL)
		return (1);
	dict = split_dict(dict_str);
	write_numbers(tab, dict);
	//free_mem()
	return (0);
}
