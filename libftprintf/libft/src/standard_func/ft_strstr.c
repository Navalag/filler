/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:58:31 by agalavan          #+#    #+#             */
/*   Updated: 2017/10/31 14:58:34 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack.
**
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		while (haystack[i] == needle[i] &&
			haystack[i] != '\0' &&
			needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
