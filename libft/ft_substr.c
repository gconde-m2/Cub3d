/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:10:48 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/18 11:30:49 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	cont;
	size_t	i;
	size_t	slen;

	cont = 0;
	i = start;
	if (!s)
		return (NULL);
	aux = (char *)malloc((len + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
	{
		aux[cont] = '\0';
		return (aux);
	}
	while (i < len + start)
	{
		aux[cont++] = s[i++];
	}
	aux[cont] = '\0';
	return (aux);
}
