/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:40:03 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/01 09:09:10 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isescape(const char *str)
{
	char	*elements;
	int		i;
	int		j;

	elements = "\t\n\v\f\r ";
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (elements[j] != '\0')
		{
			if ((elements[j] == ' ') && !(str[i] == elements[j]))
				return (i);
			if (str[i] == elements[j])
			{
				i += 1;
				break ;
			}
			j += 1;
		}
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = ft_isescape(nptr);
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i += 1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
