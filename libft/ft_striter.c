/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:19:38 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/06 15:59:53 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char			*str;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	if (!str || !f)
		return ;
	while (str[i])
	{
		(*f)(&str[i]);
		i++;
	}
}
