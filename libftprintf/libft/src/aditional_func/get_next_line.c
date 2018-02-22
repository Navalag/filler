/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:09:31 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/28 10:37:50 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../inc/libft.h"

static int		check_result(char **res, char **line)
{
	char		*tmp;

	if ((tmp = ft_strchr(*res, '\n')) != 0)
	{
		*tmp = 0;
		*line = ft_strdup(*res);
		tmp = ft_strdup(tmp + 1);
		free(*res);
		*res = tmp;
		return (1);
	}
	return (0);
}

static int		read_from_fd(const int fd, char **res, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		read_bytes;

	read_bytes = 0;
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (read_bytes == -1)
			return (-1);
		buff[read_bytes] = '\0';
		if (!(*res))
			*res = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(*res, buff);
			free(*res);
			*res = tmp;
		}
		if (check_result(res, line))
			return (1);
	}
	return (0);
}

/*
** Below function is main for this project.
**
** First - check errors.
** Then initialize line with NULL. When file is empty and GNL return 0
** line will contain NULL.
**
** After that check 4 different cases:
** -if res is empty (usually first call of GNL with given fd).
** In this case - call to read_from_fd().
** -if res is not empty. Call check_result() and check if
** there is a full line (end with \n). If yes - add this full line to result.
** -else read from buffer until find \n.
** -if this is last line in a file and it does not finish with \n
** copy res to line.
**
** GNL return 1 when line was readed, 0 when file is finished
** and -1 in case of error.
*/

int				get_next_line(const int fd, char **line)
{
	static	char	*res[FD_AMOUNT];
	int				ret_val;

	if (fd < 0 || line == NULL || (read(fd, 0, 0) < 0))
		return (-1);
	*line = NULL;
	if (!res[fd])
		ret_val = read_from_fd(fd, &res[fd], line);
	else if (check_result(&res[fd], line) == 1)
		return (1);
	else
		ret_val = read_from_fd(fd, &res[fd], line);
	if (ret_val == 0 && res[fd] != NULL && *res[fd] != '\0')
	{
		*line = ft_strdup(res[fd]);
		free(res[fd]);
		res[fd] = NULL;
		return (1);
	}
	return (ret_val);
}
