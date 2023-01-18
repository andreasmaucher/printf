/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                           :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:39:38 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/05 10:39:39 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intdec(int n)
{
	char	*numstr;
	int		nret;

	numstr = ft_itoa(n);
	nret = ft_printstr(numstr);
	free(numstr);
	return (nret);
}

int	ft_unsigned(unsigned int n)
{
	char	*numstr;
	int		nret;

	nret = 0;
	if (n < 0)
		n = 4294967295 + n;
	numstr = ft_unsigned_itoa(n);
	nret = ft_printstr(numstr);
	free(numstr);
	return (nret);
}

int	ft_percent(int c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_formatspecifier(va_list args, const char format)
{
	int	nret;

	nret = 0;
	if (format == 'c')
		nret += ft_printchar(va_arg(args, int));
	else if (format == 's')
		nret += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		nret += ft_voidpointer(va_arg(args, size_t));
	else if (format == 'd' || format == 'i')
		nret += ft_intdec(va_arg(args, int));
	else if (format == 'u')
		nret += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'X')
		nret += ft_hex(va_arg(args, unsigned int), 'X');
	else if (format == 'x')
		nret += ft_hex(va_arg(args, unsigned int), 'x');
	else if (format == '%')
		nret += ft_percent(format);
	return (nret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		nret;

	va_start(args, format);
	i = 0;
	nret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			nret += ft_formatspecifier(args, format[i]);
			i++;
		}
		else
		{
			nret += ft_printchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (nret);
}

int main()
{
	//ft_printf("%c%s%d%i%%%u%x%X%p", 'z', "hello", -10, -11, -12, 11, -1, 1);
	//printf("\n%c%s%d%i%%%u%x%X%p\n", 'z', "hello", -10, -11, -12, 11, -1, 1);
	//ft_printf("%u", -10000);
	//printf("\n%u\n", -10000);
	ft_printf("%p", -10000);
	printf("\n%p\n", -10000);
}

