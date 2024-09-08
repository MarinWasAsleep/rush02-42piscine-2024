/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:12 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 19:58:37 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

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
		write(1, "Erro0\n", 6);
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
	printf("Ready to get number\n");
	tab = get_number(number);
	printf("Number retrieved\n");
	if (tab == NULL)
	{
		write(1, "Erro1\n", 6);
		return (1);
	}
	printf("Ready to parse dict\n");
	dict_str = ft_parse_dict(path);
	printf("Dict parsed\n");
	if (dict_str == NULL)
		return (1);
	printf("Ready to split dict\n");
	dict = split_dict(dict_str);
	printf("Dict split\n");
	//write_number()
	//free_mem()
	return (0);
}
