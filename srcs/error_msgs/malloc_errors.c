/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:20:08 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/07 15:58:14 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"

void	malloc_error()
{
	ft_putendl_fd("Could'nt alloceted memory!", 2);
	exit(1);
}
