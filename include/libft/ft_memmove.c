/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:49:49 by ner-roui          #+#    #+#             */
/*   Updated: 2023/11/25 09:44:38 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_revmemcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest + n - 1;
	s = src + n - 1;
	while (n-- > 0)
		*d-- = *s--;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((!dest && !src) || dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		ft_revmemcpy(dest, src, n);
	return (dest);
}
