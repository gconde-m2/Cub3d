/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:05:54 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/19 07:58:17 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	int len;
	int it;

	it = 0;
	len = ft_strlen(set);
	while (it < len)
	{
		if (c == set[it])
			return (1);
		it++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		k;
	long int	len;
	char		*aux;
	long int	i;

	i = 0;
	k = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_inset(s1[i], set))
		i++;
	while (len > 0 && ft_inset(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	aux = (char*)malloc(sizeof(char) * (len - i + 1));
	if (!aux)
		return (NULL);
	while (i < len)
		aux[k++] = s1[i++];
	aux[k] = '\0';
	return (aux);
}
