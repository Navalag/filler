/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:34:32 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/01 10:34:34 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strcmp() and strncmp() functions lexicographically compare the null-
** terminated strings s1 and s2.
**
** The strncmp() function compares not more than n characters. Because
** strncmp() is designed for comparing strings rather than binary data, char-
** acters that appear after a `\0' character are not compared.
**
** The strcmp() and strncmp() functions return an integer greater than, equal
** to, or less than 0, according as the string s1 is greater than, equal to,
** or less than the string s2. The comparison is done using unsigned charac-
** ters, so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
