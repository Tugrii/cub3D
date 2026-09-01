/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:42:59 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/01 09:10:05 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_;
	const char	*src_;
	size_t		i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	dest_ = (char *)dest;
	src_ = (const char *)src;
	while (i < n)
	{
		dest_[i] = src_[i];
		i++;
	}
	return (dest);
}
