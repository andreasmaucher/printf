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

int	ft_hex(unsigned int n, char up_low)
{
	char	*hexstr;
	char	temp[25];
	int		nret;
	int		i;

	nret = 0;
	if (up_low == 'x')
		hexstr = "0123456789abcdef";
	else
		hexstr = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_printchar('0');
		return (nret += 1);
	}
	i = 0;
	while (n != 0)
	{
		temp[i] = hexstr[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
		nret += ft_printchar(temp[i]);
	return (nret);
}
