/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:22:55 by struxill          #+#    #+#             */
/*   Updated: 2018/12/11 20:26:53 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_m_cat(char *dst, char *src)
{
	size_t	maxlen;
	char	*str;

	str = "\0";
	if (dst && src)
	{
		maxlen = ft_strlen(dst) + ft_strlen(src);
		if (!(str = (char*)malloc(sizeof(char) * maxlen + 1)))
			return (NULL);
		ft_strncpy(str, dst, ft_strlen(dst));
		str[ft_strlen(dst)] = '\0';
		ft_strncat(str, src, maxlen);
		str[maxlen] = '\0';
	}
	return (str);
}

char	*ft_read_line(const int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = "\0";
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_str_m_cat(str, buf);
		if (ft_strchr(str, '\n') != NULL)
			break ;
	}
	if (ret == 0)
		return (NULL);
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*list1;
	char			*str;
	char			**tab;
//	char			*next_str;
//	int				i;

	if (fd == -1)
	{
		ft_putstr("Fd = -1, error\n");
		return (-1);
	}

/*	
	if (list1 != NULL)
	{
		ft_lstadd(&list1, ft_lstnew(ft_str_m_cat(list1->content, ft_read_line(fd)), ft_strlen(list1->content)));
		*line = list1->content;
		free(list1);
		return (1);
	}	
	i = 1;
	next_str = "\0";
*/

	list1 = ft_lstnew("", 0);
	str = ft_read_line(fd);
	if (str != NULL)
	{
		tab = ft_strsplit(str, '\n');
		*line = tab[0];
		ft_lstadd(&list1, ft_lstnew(tab[0], ft_strlen(tab[0])));
		*line = list1->content;
		free(list1);
		
//		while (tab[i])
//		{
//			next_str = ft_str_m_cat(next_str, tab[i]);
//			i++;
//		}
//		ft_lstadd(&list1, ft_lstnew(next_str, ft_strlen(next_str)));
		
		return (1);
	}
	return (0);
}
