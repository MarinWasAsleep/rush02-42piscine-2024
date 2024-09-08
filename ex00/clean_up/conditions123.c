/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions123.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labensou <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:13:27 by labensou          #+#    #+#             */
/*   Updated: 2024/09/08 20:56:09 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	write_log_char(t_dict *dict, char c, int size);
void	write_log_str(t_dict *dict, char *str, int size);
void	write_log_tens(t_dict *dict, char c, int size);

void	print_trans(int bloc_num, t_dict *dict)
{
	char	*bloc_trans;
	int		i;

	bloc_trans = (char *)malloc(sizeof(char) * (bloc_num - 1) * 3 + 2);
	bloc_trans[0] = '1';
	i = 1;
	while (i < (bloc_num - 1) * 3 + 2)
		bloc_trans[i++] = '0';
	bloc_trans[i] = '\0';
	if (bloc_num > 1)
	{
		write(1, " ", 1);
		//write_log_/*nom de la fonction*/(bloc_trans);
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

void	block_analysis(char *str, int bloc_num, t_dict *dict)
{
	char	teen[3];
	int		size;


	size = retrieve_dict_size(dict);
	if (str[0] >= '1' && str[0] <= '9')
		print_centaine(str[0], dict);
	if (str[0] != 0 && (str[1] != 0 || str[2] != 0))
		write(1, " and", 4);
	if (str[1] == '1' && str[2] != '0')
		print_teen(str[1], str[2], dict);
	else if (str[1] >= '1' && str[1] <= '9')
	{
		write(1, " ", 1);
		write_log_tens(dict, str[1], size);
	}
	if (str[1] >= '2' && str[1] <= '9' && str[2] >= '1' && str[2] <= '9')
		write(1, "-", 1);
	if (str[2] >= '1' && str[2] <= '9')
		write_log_char(dict, str[2], size);
	print_trans(bloc_num, dict);
}	
