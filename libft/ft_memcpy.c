/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:38:51 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/13 15:33:39 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*aux1;
	unsigned char		*aux2;

	aux1 = (const unsigned char *)src;
	aux2 = (unsigned char *)dest;
	if ((dest == NULL && src == NULL) || !n)
		return (dest);
	while (n > 0)
	{
		*aux2 = *aux1;
		aux1++;
		aux2++;
		n--;
	}
	return (dest);
}
