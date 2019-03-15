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

int		get_fd(t_list **list, int fd)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp->content_size);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(list, temp);
	return (temp->content_size);
}
/*
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
} */

char	*ft_read_line(const int fd, t_list *list_fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		i;
//	char	tmp_c;

	i = 0;
//	str = "\0";
	while ((int)list_fd->content_size != fd && list_fd->next)
		list_fd = list_fd->next;
	str = ft_str_m_cat("\0", list_fd->content);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ft_strchr(buf, '\n') == NULL)
	{
		buf[ret] = '\0';
		str = ft_str_m_cat(str, buf);
	}
	if (ret == 0)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
//	tmp_c = buf[i];
	buf[i] = '\0';
	str = ft_str_m_cat(str, buf);
//	buf[i] = tmp_c;
	buf[ret] = '\0';
	list_fd->content = ft_strdup(&buf[i + 1]);
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*list_fd;
//	int				fd_int;

	if (fd < 0 || !line || BUFF_SIZE <= 0 )
	{
		ft_putstr("Error\n");
		return (-1);
	}
//	fd_int = get_fd(&list_fd, fd);
//	printf("fd_int = %i\n", fd_int);
//	*line = ft_read_line(fd_int);
	*line = ft_read_line(get_fd(&list_fd, fd), list_fd);
//	printf("line = %s\n", *line);
	if (*line)
		return (1);
//	printf("str = %s\n", str);
	return (0);
}
