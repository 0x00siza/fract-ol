/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:58:42 by ner-roui          #+#    #+#             */
/*   Updated: 2023/11/28 12:36:46 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static	char	**ft_free(char **spit)
{
	int	idx;

	idx = 0;
	while (spit[idx]) 
		free(spit[idx++]);
	free(spit);
	return (NULL);
}

char	*fun(const char *s, size_t j)
{
	char	*puh;

	puh = (char *)ft_calloc(j + 1, 1);
	if (!puh)
		return (NULL);
	ft_strlcpy(puh, s, j + 1);
	return (puh);
}

char	**ft_split(char const *s, char c)
{
	char	**spit;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_countword(s, c);
	i = 0;
	spit = (char **)ft_calloc(l + 1, sizeof(char *));
	if (!spit)
		return (NULL);
	while (i < l)
	{
		j = 0;
		while (s[j] == c && s[j])
			s++;
		while (s[j] != c && s[j])
			j++;
		spit[i] = fun(s, j);
		if (!spit[i++])
			return (ft_free(spit));
		s += j;
	}
	return (spit);
}
