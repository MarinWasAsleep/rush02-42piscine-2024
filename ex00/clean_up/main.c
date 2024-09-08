/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:12 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 19:05:52 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int	i;
	char *number;
	char *dict_str;
	char **tab;

	if (ac != 2 || ac != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (ac == 2)
		number = av[1];
	else if (ac == 3)
		number = av[2];
	tab = get_number(str)
	dict_str = ft_parse_dict() // dict path?
	split_dict()
	write_number()
	free_mem()
}
