/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:00:30 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/15 09:24:55 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		cont;

	cont = 0;
	str = (char*)s;
	while (str[cont])
	{
		if (str[cont] == c)
			return (&str[cont]);
		cont++;
	}
	if (str[cont] == '\0' && c == '\0')
		return (&str[cont]);
	return (NULL);
}
