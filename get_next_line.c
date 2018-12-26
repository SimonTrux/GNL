/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:22:55 by struxill          #+#    #+#             */
/*   Updated: 2018/12/26 20:27:40 by struxill         ###   ########.fr       */
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

static t_list	*get_fd(t_list **list, int fd)
{
	t_list	*temp

	temp = *list;
	while (temp)
	{
		if (temp->content_size == fd)
			return (temp);
			temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(list, temp);
	return (temp);
}

char	**ft_strsplit_fd(char const *s, char c, int fd)
{
	get

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
	static t_list	*list_fd;
	t_list			*list;
	char			*str;
	char			**tab;

	if (fd < 0 || !line || BUFF_SIZE <= 0 )
	{
		ft_putstr("Error\n");
		return (-1);
	}
	list = get_fd(list_fd, fd);
	str = ft_read_line(list);
	tab = ft_strsplit(str, '\n');


	if (str != NULL)
	{
		tab = ft_strsplit(str, '\n');
		*line = tab[0];
		ft_lstadd(&list1, ft_lstnew(tab[0], ft_strlen(tab[0])));
		*line = list1->content;
		free(list1);
		return (1);
	}
	return (0);
}
