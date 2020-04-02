/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:01:36 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/08 07:35:32 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*aux;
	size_t	cont;

	cont = 0;
	aux = (char*)str;
	while (cont < n)
	{
		*aux = (char)c;
		cont++;
		aux++;
	}
	return (str);
}
