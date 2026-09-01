/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:12 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/01 09:10:36 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_dup(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dynamic_memory;
	size_t	i;

	i = 0;
	dynamic_memory = (char *)malloc(ft_strlen_dup(s) + 1);
	if (!dynamic_memory)
		return (NULL);
	while (s[i] != '\0')
	{
		dynamic_memory[i] = s[i];
		i++;
	}
	dynamic_memory[i] = '\0';
	return (dynamic_memory);
}
