/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 07:42:48 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/19 06:01:54 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *aux;

	aux = *alst;
	if (!aux)
	{
		*alst = new;
	}
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}
