/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:06:40 by struxill          #+#    #+#             */
/*   Updated: 2019/03/21 18:47:58 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_get_fd(t_list **list_fd, int fd)
{
	t_list			*tmp;

	tmp = *list_fd;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list_fd, tmp);
	tmp = *list_fd;
	return (tmp);
}

char			*ft_strjoin_free(char *s1, char *s2)
{
	char			*retstr;
	size_t			maxlen;

	retstr = NULL;
	if (s1 && s2)
	{
		maxlen = ft_strlen(s1) + ft_strlen(s2);
		if (!(retstr = (char*)malloc(sizeof(char) * maxlen + 1)))
			return (NULL);
		ft_strcpy(retstr, s1);
		ft_strncat(retstr, s2, maxlen);
		free(s1);
	}
	return (retstr);
}

int				ft_str_c_line(char **line, char *str, char c)
{
	int				i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!(*line = ft_strnew(i)))
		return (0);
	ft_strncpy(*line, str, i);
	return (i);
}

char			*ft_strndup(char *str, int i)
{
	char			*tmp;

	tmp = str;
	str = ft_strdup(str + i);
	free(tmp);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list_fd;
	t_list			*str;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				len;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	str = ft_get_fd(&list_fd, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(str->content = ft_strjoin_free(str->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(str->content))
		return (0);
	len = ft_str_c_line(line, str->content, '\n');
	if (len < (int)ft_strlen(str->content))
		str->content = ft_strndup(str->content, len + 1);
	else
		ft_strclr(str->content);
	return (1);
}
