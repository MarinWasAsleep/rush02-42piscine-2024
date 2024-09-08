/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeinoz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:12:34 by dgeinoz           #+#    #+#             */
/*   Updated: 2024/09/08 22:15:09 by dgeinoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *get_trans_str(int index, int **tab)
{
	char *str;
	int num_of_zero;
	int triplet_num;
	int i;
	
	i = 0;
	triplet_num = 0;
	while (tab[triplet_num])
	{
		triplet_num++;
	}
	num_of_zero = (triplet_num - (index + 1)) * 3;
	str = malloc(sizeof(char) * (num_of_zero + 1 + 1));
	str[0] = '1';
	while (i < num_of_zero)
	{
		str[i + 1] = '0';
	}
	return (str);
}

