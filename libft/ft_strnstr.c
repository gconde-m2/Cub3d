/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:11:28 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/13 18:12:07 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	char			*aux1;
	char			*aux2;

	if (!*s2)
		return ((char *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			i = n;
			aux1 = (char *)s1 + 1;
			aux2 = (char *)s2 + 1;
			while (i-- && *aux1 && *aux2 && *aux1 == *aux2)
			{
				++aux1;
				++aux2;
			}
			if (!*aux2)
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}
