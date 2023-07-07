/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:23:26 by mkarabog          #+#    #+#             */
/*   Updated: 2023/07/07 02:25:28 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0 && !dst)
		return (srclen);
	dstlen = ft_strlen(dst);
	j = dstlen;
	if (dstsize <= j)
		return (dstsize + srclen);
	while (j + 1 < dstsize)
		dst[j++] = src[i++];
	return (dstlen + srclen);
}
