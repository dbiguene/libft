/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:08:11 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/11 10:27:36 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_int_exception(void)
{
	char	*str;

	str = malloc(12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

void	init(int *len, int *sign, int *factor, int *n)
{
	*factor = 1;
	*sign = 0;
	if (*n < 0)
	{
		*n *= -1;
		*sign = 1;
	}
	*len = *sign + 1;
	while (*factor <= *n / 10)
	{
		*factor *= 10;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	int		factor;
	int		i;
	int		len;
	int		sign;
	char	*str;

	if (n == -2147483648)
		return (min_int_exception());
	init(&len, &sign, &factor, &n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	if (sign)
		str[++i] = '-';
	while (++i < len)
	{
		str[i] = (n / factor) + 48;
		n %= factor;
		factor /= 10;
	}
	return (str);
}