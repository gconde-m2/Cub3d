/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:50:04 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/18 16:02:55 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int k;

	k = n;
	if (k < 0)
	{
		ft_putchar_fd('-', fd);
		k = -k;
	}
	if (k > 9)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
	else
		ft_putchar_fd(k + '0', fd);
}
