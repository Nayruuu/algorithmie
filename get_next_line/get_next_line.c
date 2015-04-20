/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:50:11 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/05 18:09:12 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_files		*ft_structrealloc(t_files *save, int pos)
{
	int				i;
	int				*new_fd;
	char			**new_tab;

	i = 0;
	if (!(new_tab = (char**)malloc((pos + 1) * sizeof(char*))) ||
		!(new_fd = (int*)malloc((pos + 1) * sizeof(int))))
		return (NULL);
	while (i < pos)
	{
		new_fd[i] = save->file_des[i];
		new_tab[i] = ft_strdup(save->content[i]);
		i++;
	}
	i = 0;
	ft_memdel((void**)&save->file_des);
	while (i < pos)
	{
		ft_strdel(&save->content[i]);
		i++;
	}
	ft_memdel((void**)save->content);
	save->file_des = new_fd;
	save->content = new_tab;
	return (save);
}

static t_files		*init_env(t_files *save, int fd, int pos)
{
	if (save == NULL)
	{
		save = (t_files*)malloc(sizeof(t_files));
		save->file_des = ft_memalloc(2);
		save->content = (char**)malloc(1 * sizeof(char*));
	}
	else
	{
		save = ft_structrealloc(save, pos);
	}
	if (save && save->content && save->file_des)
	{
		save->file_des[pos] = fd;
		save->file_des[pos + 1] = -1;
		if (!(save->content[pos] = ft_strnew(BUFF_SIZE)))
			return (NULL);
	}
	return (save);
}

static int			get_line(t_files *save, char **line, int pos)
{
	int				ret;
	char			*ptr;
	char			r_str[BUFF_SIZE + 1];

	if (!(*line = ft_strdup(save->content[pos])))
		return (ERROR);
	while (!(ptr = ft_strchr(*line, '\n')) &&
			(ret = read(save->file_des[pos], r_str, BUFF_SIZE)) > 0)
	{
		r_str[ret] = '\0';
		if (!(*line = ft_memrealloc(*line, ft_strlen(*line) + BUFF_SIZE)))
			return (ERROR);
		ft_strcat(*line, r_str);
	}
	if (ptr && ret != ERROR)
	{
		*ptr = '\0';
		ptr++;
		ft_strdel(&save->content[pos]);
		if (!(save->content[pos] = ft_strdup(ptr)))
			return (ERROR);
	}
	if (ret == 0 && *line[0] == '\0')
		return (0);
	return ((ret == ERROR) ? ERROR : 1);
}

int					get_next_line(int fd, char **line)
{
	int				pos;
	static	t_files	*save;

	pos = 0;
	if (fd == ERROR || BUFF_SIZE < 0 || !line)
		return (ERROR);
	if (save == NULL)
	{
		if (!(save = init_env(save, fd, pos)))
			return (ERROR);
	}
	else
	{
		while (save->file_des[pos] != -1)
		{
			if (save->file_des[pos] == fd)
				break ;
			pos++;
		}
		if (save->file_des[pos] != fd)
			if (!(save = init_env(save, fd, pos)))
				return (ERROR);
	}
	return (get_line(save, line, pos));
}
