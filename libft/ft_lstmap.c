/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:38:00 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 17:13:30 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *new;

	new = (*f)(lst);
	start = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = (*f)(lst);
		if (new->next == NULL)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (start);
}
