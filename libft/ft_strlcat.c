/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:09:18 by aymoulou          #+#    #+#             */
/*   Updated: 2021/11/12 15:52:42 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;
	size_t	cut;
	size_t	res;

	cut = 0;
	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	if (size > ldst)
	{
		cut = size - ldst - 1;
		res = ldst + lsrc;
	}
	else
		res = lsrc + size;
	i = 0;
	while (i < cut && src[i])
		dst[ldst++] = src[i++];
	if (cut)
		dst[ldst] = '\0';
	return (res);
}
