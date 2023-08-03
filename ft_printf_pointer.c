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

int	ft_voidpointer(uintptr_t p)
{
	char	*hexstr;
	char	temp[25];
	int		nret;
	int		i;

	nret = 0;
	hexstr = "0123456789abcdef";
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	nret += 2;
	i = 0;
	while (p != 0)
	{
		temp[i] = hexstr[p % 16];
		p = p / 16;
		i++;
	}
	while (i--)
		nret += ft_printchar(temp[i]);
	return (nret);
}
