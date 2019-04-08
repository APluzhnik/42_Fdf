/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:53:55 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/04 18:36:00 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)h;
	if (!ft_strlen(n))
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
