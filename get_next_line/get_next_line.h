/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:45:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/05 17:23:52 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 1
# define ERROR (-1)

typedef struct		s_files
{
	char			**content;
	int				*file_des;
}					t_files;

int					get_next_line(int fd, char **line);

#endif
