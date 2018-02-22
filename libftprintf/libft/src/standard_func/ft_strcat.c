/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:27:02 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/01 15:27:06 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strcat() function append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a terminat-
** ing `\0'. The string s1 must have sufficient space to hold the result.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** The strcat() function return the pointer s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[j + i] = s2[j];
		j++;
	}
	s1[j + i] = '\0';
	return (s1);
}
