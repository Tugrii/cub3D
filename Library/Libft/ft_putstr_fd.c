/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:43:43 by tgeler            #+#    #+#             */
/*   Updated: 2026/10/07 13:43:57 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	return ;
}
