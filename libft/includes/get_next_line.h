/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:19:23 by pfournet          #+#    #+#             */
/*   Updated: 2014/12/02 14:07:08 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFF 100000

typedef struct	s_lst
{
	char			*buf;
	int				fd;
	struct s_lst	*next;
}				t_lst;
int				get_next_line(int const fd, char **line);

#endif
