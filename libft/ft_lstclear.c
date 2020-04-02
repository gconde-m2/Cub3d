/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:06:31 by gconde-m          #+#    #+#             */
/*   Updated: 2019/11/19 05:57:50 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;
	t_list *tmp;

	aux = *lst;
	while (aux)
	{
		tmp = aux->next;
		del(aux->content);
		free(aux);
		aux = tmp;
	}
	*lst = NULL;
}
