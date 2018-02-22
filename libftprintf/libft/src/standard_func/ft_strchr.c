/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:43:01 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/02 15:43:04 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s. The terminating null character is
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
**
** The function strchr() return a pointer to the located char-
** acter, or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char*)&s[i]);
	return (0);
}
