/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:28:41 by struxill          #+#    #+#             */
/*   Updated: 2018/12/02 22:02:44 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


int	main(void)
{
	int		fd;
	char	*line = NULL;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	close(fd);
	return (0);
}
