/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeinoz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:27:04 by dgeinoz           #+#    #+#             */
/*   Updated: 2024/09/08 19:31:38 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_parse_dict(char *dict_path)
{
	int		file;
	int		c_count;
	char	*dict;
	char	read_seg[1];

	c_count = 0;
	file = open(dict_path, O_RDONLY);
	if (file < 0)
	{
		ft_putstr("Error in opening the file");
		return (dict);
	}
	while (read(file, read_seg, 1))
		c_count += 1;
	close(file);
	dict = (char *)malloc(sizeof(char) * (c_count + 1));
	file = open(dict_path, O_RDONLY);
	if (file < 0)
	{
		ft_putstr("Error in opening the file");
		return (dict);
	}
	read(file, dict, c_count);
	close(file);
	return (dict);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	ft_parse_dict(av[1]);
	return (0);
}
*/
