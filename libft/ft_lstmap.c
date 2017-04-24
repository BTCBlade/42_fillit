/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 23:25:00 by tochen            #+#    #+#             */
/*   Updated: 2017/03/15 10:08:23 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

tetri_list			*ft_lstmap(tetri_list *lst, tetri_list *(*f)(tetri_list *))
{
	tetri_list		*new;
	tetri_list		*head;

	if (!lst || !f)
		return (0);
	new = f(lst);
	head = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (head);
}
