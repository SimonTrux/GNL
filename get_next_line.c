/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:22:55 by struxill          #+#    #+#             */
/*   Updated: 2018/12/02 22:02:36 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	size_t			len;
	static t_list	*list1;

	len = 0;
	if (fd == -1)
	{
		ft_putstr("Fd = -1, error\n");
		return (-1);
	}
	list1 = ft_lstnew("", 0);
	if ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') == NULL;
			tempstr = 
		ft_lstadd(&list1, ft_lstnew(buf, BUFF_SIZE));
		while 
		*line = list1->content;
//		ft_putstr(*line);
	}
	//	ft_lst_aff(list1);
	/*
	   if ((ret = read(fd, buf, BUFF_SIZE)))
	   {
	   printf("buf : %s\n", buf);
	   while (buf[len] != '\n')
	   len++;
	   if (!(*line = malloc(sizeof(buf) * len)))
	   return (0);
	   } */
	if (ret != 0)
		return (1);
	return (0);
}
