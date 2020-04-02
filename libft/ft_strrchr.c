/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:14:20 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/13 18:07:33 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		cont;

	cont = 0;
	str = (char*)s;
	while (str[cont])
		cont++;
	while (cont >= 0)
	{
		if (str[cont] == c)
			return (&str[cont]);
		cont--;
	}
	return (NULL);
}
