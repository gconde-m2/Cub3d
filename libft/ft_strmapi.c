/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:03:15 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/19 05:52:35 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*aux;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	aux = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	while (s[i])
	{
		aux[i] = f(i, s[i]);
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
