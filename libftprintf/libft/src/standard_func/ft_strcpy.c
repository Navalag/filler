/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:17:43 by agalavan          #+#    #+#             */
/*   Updated: 2017/10/31 12:17:48 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The stpcpy() function copy the string src to dst (including
** the terminating `\0' character.)
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** The strcpy() function return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
