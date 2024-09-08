/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:04:33 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/08 19:04:35 by imeulema         ###   ########.fr       */
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

#endif
