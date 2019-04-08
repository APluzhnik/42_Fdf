/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:12:43 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/06 16:15:18 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(t = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		t[i] = s[start];
		i++;
		start++;
	}
	t[i] = '\0';
	return (t);
}
