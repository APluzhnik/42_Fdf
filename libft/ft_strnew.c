/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:05:23 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/06 15:52:29 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	s = malloc(sizeof(char) * size + 1);
	i = 0;
	if (!s)
		return (0);
	while (i <= size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
