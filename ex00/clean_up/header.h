/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:04:33 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 22:17:31 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*index;
	int		index_size;
	char	*log;
	int		log_size;
}	t_dict;

t_dict	*split_dict(char *str);
void	block_analysis(char *str, int bloc_num, t_dict *dict);
void	write_log_char(t_dict *dict, char c, int size);
void	write_log_str(t_dict *dict, char *str, int size);
void	write_log_tens(t_dict *dict, char c, int size);
void	write_numbers(char **tab, t_dict *dict);
char	**get_number(char *str);
char	*ft_parse_dict(char *dict_path);
char	*get_trans_str(int index, int **tab);
int	skip_whitespaces(char *str);
int	retrieve_dict_size(t_dict *dict);
int	get_len(char *str, int i);
int	get_tab_size(int len);
int	get_dict_size(char *str);
int	ft_strcmp(char *s1, char *s2);

#endif
