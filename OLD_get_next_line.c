/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:22:55 by struxill          #+#    #+#             */
/*   Updated: 2018/12/11 19:31:17 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buf_line(char *buf)
{
	char	*retstr;
	size_t	i;

	i = 0;
	if (ft_strchr(buf, '\n') == NULL)
	{
		retstr = ft_strnew(ft_strlen(buf));
		ft_strncpy(retstr, buf, ft_strlen(buf));
	}
	else
	{
		while (buf[i] != '\n')
			i++;
		retstr = ft_strnew(i);
		ft_strncpy(retstr, buf, i);
	}
	return (retstr);
}

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
	int		flag;
	char	*str;
	int 	i;

	i = 0;
	flag = 0;
	str = "\0";
	while ((ret = read(fd, buf, BUFF_SIZE)) && flag == 0)
	{
		if (ft_strchr(buf, '\n') == NULL)
		{
			buf[ret] = '\0';
			printf("if buf is : %s\n----\n", buf);
			str = ft_str_m_cat(str, buf);
		}
		else
		{
			flag = 1;
			while (buf[i] != '\n')
				i++;
			ret = i;	
			printf("else buf before /0 is : %s\n----\n", buf);
			buf[ret] = '\0';
			printf("else buf after /0 is : %s\n----\n", buf);
			str = ft_str_m_cat(str, buf);
		}
	}
	if (flag == 0 && ret == 0)
		return (NULL);
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*list1;
	char			*str;

	if (fd == -1)
	{
		ft_putstr("Fd = -1, error\n");
		return (-1);
	}
	list1 = ft_lstnew("", 0);
	str = ft_read_line(fd);
	if (str != NULL)
	{
		ft_lstadd(&list1, ft_lstnew(str, ft_strlen(str)));
		*line = list1->content;
		return (1);
	}
	return (0);
}
