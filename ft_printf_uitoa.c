/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:48:35 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/13 11:48:37 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoa_unsigned_num_digits(unsigned long long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits++;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*ft_itoa_unsigned_conditions(char *str, unsigned long long n)
{
	int	i;

	i = ft_itoa_unsigned_num_digits(n);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_unsigned_itoa(unsigned long long n)
{
	int		i;
	char	*str;

	i = ft_itoa_unsigned_num_digits(n);
	str = malloc((sizeof(char) * (i + 1)));
	if (str == NULL)
		return (NULL);
	return (ft_itoa_unsigned_conditions(str, n));
}
