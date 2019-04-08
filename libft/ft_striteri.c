/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:22:16 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/05 17:01:18 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	if (!str || !f)
		return ;
	while (str[i])
	{
		(*f)(i, &str[i]);
		i++;
	}
}
