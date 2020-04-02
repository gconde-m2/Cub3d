/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:09:17 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/13 18:09:39 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	if (n == 0)
		return (0);
	cont = 0;
	while (s1[cont] && s2[cont] && s1[cont] == s2[cont] && cont < n - 1)
		cont++;
	return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
}
