/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:35:45 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/13 10:30:21 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

/*
** Description: Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL. Example:
** ft_strsplit("*hello*fellow***students*", ’*’) returns
** the array ["hello", "fellow", "students"].
**
** Param. #1 The string to split.
** Param. #2 The delimiter character.
**
** Return value: The array of “fresh” strings result of the split.
** Libc functions: malloc(3), free(3)
*/

static	int		ft_words_count(char const *str, char c)
{
	int sp_words;
	int i;
	int indicator;

	i = 0;
	sp_words = 0;
	while (str[i] != '\0')
	{
		indicator = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			indicator = 1;
			i++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
		if (indicator == 1)
			sp_words++;
	}
	return (sp_words);
}

static	int		ft_word_lenght(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] == c && str[i] != '\0')
		str++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static	char	**ft_add_words(char const *s, char c, int count, char **words)
{
	int		words_entered;
	int		i;
	char	*word;

	words_entered = 0;
	while (words_entered < count)
	{
		i = 0;
		if (!(word = (char*)malloc(sizeof(char) * (ft_word_lenght(s, c) + 1))))
			return (NULL);
		while (s[0] == c && s[0] != '\0')
			s++;
		while (s[0] != c && s[0] != '\0')
			word[i++] = *s++;
		word[i] = '\0';
		words[words_entered++] = word;
	}
	words[count] = 0;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words_count;
	char	**words;

	if (!s || !c)
		return (NULL);
	words_count = ft_words_count(s, c);
	if (!(words = (char**)malloc(sizeof(char*) * (words_count + 1))))
		return (NULL);
	return (ft_add_words(s, c, words_count, words));
}
