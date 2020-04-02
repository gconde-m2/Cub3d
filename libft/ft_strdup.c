/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:17:51 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/18 16:03:47 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	aux = (char*)malloc(sizeof(char) * (size + 1));
	if (aux == 0)
		return (0);
	while (s[i])
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
