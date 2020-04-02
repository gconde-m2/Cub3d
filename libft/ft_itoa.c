/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:18:37 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/18 11:18:56 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int		aux;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	aux = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (aux /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
