/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:22:58 by struxill          #+#    #+#             */
/*   Updated: 2018/11/27 17:33:38 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "../Libft/libft.h"

typedef struct 	s_list
{
	int				fd;
	char			*cline;
	struct s_list	*next;
	struct s_list	*start;
}				list;
#endif
