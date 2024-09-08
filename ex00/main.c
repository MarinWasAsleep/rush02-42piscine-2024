/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:46:06 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 17:44:40 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "header.h"

#include <stdio.h>

void	print_logs(t_dict *dict, char **tab, int nb_of_elements_in_tab);
t_dict	*split_dict(char *str);
int		ft_strlen(char *str);
void	block_analysis(char a, char b, char c, int bloc_num, t_dict *dict);

void	print_result(char **tab, int nb_of_elements_in_tab)
{
	int	i;

	i = 0;
	while (i < nb_of_elements_in_tab)
	{
		write(1, tab[i], ft_strlen(tab[i]));
		if (i + 1 < nb_of_elements_in_tab)
			write(1, " ' ", 3);
		i++;
	}
	write(1, "\n", 1);
}

void	rev_tab(char **tab, int nb_of_elements_in_tab)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = nb_of_elements_in_tab - 1;
	while (i < nb_of_elements_in_tab / 2)
	{
		ptr = tab[i];
		tab[i] = tab[j];
		tab[j] = ptr;
		i++;
		j--;
	}
}

int	main(int ac, char **av)
{
	// temporaire, il faudra adapter en fonction de ac = 2 ou ac = 3
	// et deplacer la condition sous la declaration des variables
	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	int	i;
	int minus;
	int	len;
	char **tab;
	char *str = av[1]; // a modifier par la suite
	
	// passe les whitespaces, comptabilise les - et obtient la longueur
	// du nombre
	i = 0;
	minus = 0;
	len = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		len++;
	}

	// condition demandee dans la consigne: imprimer error si nb negatif
	if (minus % 2 == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	// separe le nombre en blocs de 3 valeurs (centaines / dizaines / unites)
	// prototype avec etapes simplifiables

	// determiner le nombre d'elements a allouer pour le tableau de strings (=blocs de 3)
	int nb_of_elements_in_tab;
	if (len % 3 == 0)
		nb_of_elements_in_tab = len / 3;
	else
		nb_of_elements_in_tab = len / 3 + 1;
	tab = (char **) malloc(nb_of_elements_in_tab * sizeof(char *));
	if (tab == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	int tab_0_size = len % 3;

	tab[0] = (char *) malloc(4 * sizeof(char));
	int j = 0;
	i -= len;
	while (j < 3 - tab_0_size)
	{
		tab[0][j] = '0';
		j++;
	}
	while (j < 3)
	{
		tab[0][j] = str[i];
		j++;
		i++;
	}
	tab[0][j] = 0;
	
	j = 1;
	while (j < nb_of_elements_in_tab)
	{
		tab[j] = (char *) malloc(4 * sizeof(char));
		if (tab[j] == NULL)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		j++;
	}

	// peuple les strings avec les valeurs passees par str
	int	index;
	j = 0;
	index = 1;
	while (index < nb_of_elements_in_tab)
	{
		j = 0;
		while (j < 3)
		{
			tab[index][j] = str[i];
			i++;
			j++;
		}
		tab[index][j] = 0;
		index++;
	}

	//print_result(tab, nb_of_elements_in_tab);
	//rev_tab(tab, nb_of_elements_in_tab);
	print_result(tab, nb_of_elements_in_tab);
	



	int file;
	int read_;
	int c_count;
	char *dict;
	char read_seg[2];
	t_dict *full_dict;
	int x;

	read_seg[1] = '\0';
	c_count = 0;
	read_ = 1;
	file = open("numbers.dict", O_RDONLY);
	if (file < 0)
	{
		printf("Error in opening the file");
		return (0);
	}
	while (read_)
	{
		read_ = read(file, read_seg, 1);
		c_count += read_;
	}
	close(file);
	dict = (char *)malloc(sizeof(char) * (c_count + 1));

	file = open("numbers.dict", O_RDONLY);
	x = 0;
	while (x <= c_count)
	{
		read_ = read(file, read_seg, 1);
		dict[x] = read_seg[0];
		x++;
	}
	close(file);
	dict[x] = '\0';

	full_dict = split_dict(dict);
/*	x = 0;
	while (x < nb_of_elements_in_tab)
	{
		block_analysis(tab[x][0], tab[x][1], tab[x][2], x + 1, full_dict);
		x++;
	}*/
	print_logs(full_dict, tab, nb_of_elements_in_tab);
	free(dict);
	//printf("%d\n", c_count);
	//printf("%s", dict);
	//return (0);




	// libere la memoire allouee
	index = 0;
	while (index < nb_of_elements_in_tab)
	{
		free(tab[index]);
		index++;
	}
	free(tab);

	return (0);
}
