/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions123.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labensou <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:13:27 by labensou          #+#    #+#             */
/*   Updated: 2024/09/08 22:27:19 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_trans(int bloc_num, t_dict *dict, char **tab)
{
	char	*bloc_trans;
	int		i;
	int		size;

	size = retrieve_dict_size(dict);
	bloc_trans = (char *)malloc(sizeof(char) * (bloc_num - 1) * 3 + 2);
	bloc_trans[0] = '1';
	i = 1;
	while (i < (bloc_num - 1) * 3 + 2)
		bloc_trans[i++] = '0';
	bloc_trans[i] = '\0';
	if (bloc_num > 1)
	{
		write(1, " ", 1);
		write_log_str(dict, get_trans_str(bloc_num, tab), ft_strlen(get_trans_str(bloc_num, tab)));
	}
}

void	print_centaine(char a, t_dict *dict)
{
	int	size;

	size = retrieve_dict_size(dict);
	write_log_char(dict, a, size);
	write_log_str(dict, "100", size);
}

void	print_teen(char b, char c, t_dict *dict)
{
	int		size;
	char	teen[3];

	size = retrieve_dict_size(dict);
	write(1, " ", 1);
	teen[0] = b;
	teen[1] = c;
	teen[2] = 0;
	write_log_str(dict, teen, size);
}

void	block_analysis(char **tab, int bloc_num, t_dict *dict)
{
	char	teen[3];
	int		size;
	int		i;

	i = 0;
	size = retrieve_dict_size(dict);
	while (tab[i] != NULL)
	{
		if (tab[i][0] >= '1' && tab[i][0] <= '9')
			print_centaine(tab[i][0], dict);
		if (tab[i][0] != 0 && (tab[i][1] != 0 || tab[i][2] != 0))
			write(1, " and", 4);
		if (tab[i][1] == '1' && tab[i][2] != '0')
			print_teen(tab[i][1], tab[i][2], dict);
		else if (tab[i][1] >= '1' && tab[i][1] <= '9')
		{
			write(1, " ", 1);
			write_log_tens(dict, tab[i][1], size);
		}
		if (tab[i][1] >= '2' && tab[i][1] <= '9' && tab[i][2] >= '1' && tab[i][2] <= '9')
			write(1, "-", 1);
		if (tab[i][2] >= '1' && tab[i][2] <= '9')
			write_log_char(dict, tab[i][2], size);
		print_trans(bloc_num, dict, tab);
	}
}	
