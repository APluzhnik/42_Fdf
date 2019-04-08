/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:54:03 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/02 16:58:42 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strlen(dst);
	if (len <= size)
		return (ft_strlen(src) + len);
	ft_strncat(dst, src, len - size - 1);
	return (ft_strlen(src) + size);
}
