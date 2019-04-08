/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:00 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/08 14:30:33 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(*f)(const void *, const void*, size_t))
{
	void *lstcont;

	if (!lst || !f)
		return (NULL);
	lstcont = lst->content;
	lst = lst->next;
	while (lst)
	{
		lstcont = (*f)(lstcont, lst->content, lst->content_size);
		lst = lst->next;
	}
	return (lstcont);
}
