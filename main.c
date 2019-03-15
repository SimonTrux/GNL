/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:28:41 by struxill          #+#    #+#             */
/*   Updated: 2018/12/11 20:26:51 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


int	main(void)
{
	int		fd;
	char	*line = NULL;
	int		i;
/*	char	*str1 = "Hello there.";
	char	*str2 = " What ?\n";
	char	*str3;
	char	*str4 = "This is my second line\n";
	char	*str5;
	////////////////

	str3 = ft_str_m_cat(str1, str2);
	str3 = ft_str_m_cat(str3, str4);
	ft_putstr(str3);
	ft_putstr("\n-------------\n");

	fd = open("text.txt", O_RDONLY);
	str5 = ft_read_line(fd);
	ft_putstr(str5);
	close(fd);





	ft_putstr("\n-------------\n");
	ft_putstr("\n-------------\n");
*/
	////////////////////
	i = 1;
	fd = open("text.txt", O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
	//		printf("line %i\n", i);
			ft_putstr(line);
			ft_putstr("\n");
	//		i++;
		}
	close(fd);
	return (0);
}
