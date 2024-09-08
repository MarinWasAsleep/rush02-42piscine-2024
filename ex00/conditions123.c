
// a -> centaine -> str[i]
// b -> dizaine  -> str[i + 1]
// c -> unite    -> str[i + 2]

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void	write_log_char(t_dict *dict, char c, int size);
void	write_log_str(t_dict *dict, char *str, int size);
void	write_log_tens(t_dict *dict, char c, int size);

int	get_dict_size(t_dict *dict);

void block_analysis(char a, char b, char c, int bloc_num, t_dict *dict)
{
	char *bloc_trans;
	char teen[3]; // pas sur s'il faut 2 ou 3 pour backslash zero
	int i;
	int size;

	size = get_dict_size(dict);
	bloc_trans = (char *)malloc(sizeof(char) * (bloc_num - 1) * 3 + 2);

	if (a >= '1' && a <= '9')
	{	
		write_log_char(dict, a, size);
		write_log_str(dict, "100", size);
	}
	if (a != 0 && (b !=0 || c != 0))
		write(1, " and", 4);
	if (b == '1' && c != '0')
	{	
		write(1, " ", 1);
		teen[0] = b;
		teen[1] = c;
		teen[2] = 0;
		write_log_str(dict, teen, size);
	}
	else if (b  >= '1' && b <= '9')
	{
		write(1, " ", 1);
		write_log_tens(dict, b, size);
	}
	if (b >= '2' && b <= '9' && c >= '1' && c <= '9')
		write(1, "-", 1);
	if (c >= '1' && c <= '9')
		write_log_char(dict, c, size);
	//transition thousand, million, billion,...
	bloc_trans[0] = '1';
	i = 1;
	while (i < (bloc_num - 1) * 3 + 2)
	{	
		bloc_trans[i] = '0';
		i++;
	}
	bloc_trans[i] = '\0';
	/*
	if (bloc_num > 1)
	{
		write(1, " ", 1);
		(bloc_trans);
	}
	*/
}	
