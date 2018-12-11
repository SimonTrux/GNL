/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:22:58 by struxill          #+#    #+#             */
/*   Updated: 2018/12/11 18:03:45 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>


# include <stdio.h>

int	get_next_line(const int fd, char **line);
///////
char	*ft_str_m_cat(char *dst, char *src);
char	*ft_read_line(int fd);


/////////
typedef struct 	n_list
{
	int				fd;
	char			*cline;
	struct s_list	*next;
	struct s_list	*start;
}				list;
#endif
