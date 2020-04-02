/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:41:14 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/13 18:28:42 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cont;
	int		cont2;
	char	*dest;

	cont2 = 0;
	cont = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[cont])
	{
		dest[cont] = s1[cont];
		cont++;
	}
	while (s2[cont2])
	{
		dest[cont] = s2[cont2];
		cont++;
		cont2++;
	}
	dest[cont] = '\0';
	return (dest);
}
