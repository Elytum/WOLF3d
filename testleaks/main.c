/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 16:30:30 by achazal           #+#    #+#             */
/*   Updated: 2015/01/29 16:32:16 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char *str;

	fd = open("big", O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		printf("%s\n", str);
		free (str);
	}
}
