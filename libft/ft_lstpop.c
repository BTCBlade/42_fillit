/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:10:42 by tochen            #+#    #+#             */
/*   Updated: 2017/03/24 16:41:50 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

tetri_list			*ft_lstpop(tetri_list **alst)
{
	tetri_list		*head;
	tetri_list		*next;
	if (!alst || !(*alst))
		return (0);
	head = *alst;
	next = (*alst)->next;
	*alst = next;

	return (head);
}

int		main(void)
{
	tetri_list		*node_test1;
	tetri_list		*node_test2;
	char		str[15] = "Hello World";
	char		str2[15] = "2nd node";
	node_test1 = (tetri_list *)malloc(sizeof(tetri_list));
	node_test2 = (tetri_list *)malloc(sizeof(tetri_list));
	node_test1->content = (void *)str;
	node_test1->next = node_test2;
	node_test2->content = (void *)str2;

	printf("%s\n", (char *)(node_test1->content));
	printf("%s\n", (char *)(node_test1->next->content));
	return (0);
}

