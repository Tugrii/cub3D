/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line_format_suitable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 08:08:44 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/08 09:38:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	make_line_format_suitable(char *line_content, int *line_len)
{
	if (*line_len >= 1)
	{
		if (line_content[*line_len - 1] == '\n')
		{
			line_content[*line_len - 1] = '\0';
			*line_len -=1;
		}
	}
	if (*line_len > 1)
	{
		if (line_content[*line_len - 1] == '\r')
		{
			line_content[*line_len - 1] = '\0';
			*line_len -= 1;
		}
	}
}
