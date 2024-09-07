/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeinoz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:27:04 by dgeinoz           #+#    #+#             */
/*   Updated: 2024/09/07 18:48:48 by dgeinoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int file;
	int read_;
	int c_count;
	char *dict;
	char read_seg[2];
	int i;
	
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
	i = 0;
	while (i <= c_count)
	{
		read_ = read(file, read_seg, 1);
		dict[i] = read_seg[0];
		i++;
	}
	close(file);
	dict[i] = '\0';

	printf("%d\n", c_count);
	printf("%s", dict);
	return (0);
}
