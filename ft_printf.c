/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:39:38 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/05 10:39:39 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

//** NOTE: printf returns the numbers of characters that are printed
//** and it is a variadic function by default

int	ft_printchar(int c)
{
	int nret;
	
	nret = 0;
	write(1, &c, 1);
	nret++;
	return (nret);
}
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	//if (str[i] == NULL)
	//	ft_strdup("");
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s);
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (NULL);
	while (s[i] != '\0')
	{
		duplicate[i] = (char)s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

static int	num_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits++;
	if (n < 0)
	{
		n = n * -1;
		digits++;
	}
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*ft_conditions(char *str, int n)
{
	int	i;

	i = num_digits(n);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = 45;
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = num_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((sizeof(char) * (i + 1)));
	if (str == NULL)
		return (NULL);
	return (ft_conditions(str, n));
}

int	ft_intdec(int n)
{
	char	*numstr;
	int	nret;

	numstr = ft_itoa(n); // converting int to string
	nret = ft_printstr(numstr); // writing & determing string length
	return(nret);
}

static int	ft_itoa_unsigned_num_digits(int n)
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

static char	*ft_itoa_unsigned_conditions(char *str, int n)
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

char	*ft_unsigned_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_itoa_unsigned_num_digits(n);
	str = malloc((sizeof(char) * (i + 1)));
	if (str == NULL)
		return (NULL);
	return (ft_itoa_unsigned_conditions(str, n));
}

int	ft_unsigned(unsigned int n)
{
	char	*numstr;
	int	nret;

	numstr = ft_unsigned_itoa(n); // converting int to string
	nret = ft_printstr(numstr); // writing & determing string length
	return(nret);
}

int	ft_percent(int c)
{
	int i;

	i = 0;
	write(1, &c, 1); // also "%" possible
	i++;
	return(i);
}

int	ft_hex(int n, char up_low)
{
	char	*hexstr;
	int	nret;

	nret = 0;
	if (up_low == 'x')
		hexstr = "0123456789abcdef";
	else
		hexstr = "0123456789ABCDEF";
	if (n < 16)
	{
		write(1, &hexstr[n], 1);
		nret++;
	}
	else if (n >= 16)
	{
		ft_hex(n / 16, up_low);
		ft_hex(n % 16, up_low);
	}
	return (nret);
}
/*
int	ft_voidpointer(void *p) // prints the address at which the pointer is stored
							// transform each byte to hexadecimal
{
	int	nret;

	nret = 0;
	write(1, "0x", 1);
	nret += 2;
	ft
	
	uintptr_t // unsigned int type that is capable of storing a data pointer
}
*/
int	ft_formatspecifier(va_list args, const char format)
{
	int nret;

	nret = 0;
	if (format == 'c')
		nret += ft_printchar(va_arg(args, int));
	else if (format == 's')
		nret += ft_printstr(va_arg(args, char *));
		/*
	else if (format == 'p') // void pointer (has no associated data type with it)
		nret += ft_voidpointer(va_arg(args, void *)); */
	else if (format == 'd' || format == 'i') // why do decimals come here as well
		nret += ft_intdec(va_arg(args, int));
	else if (format == 'u')
		nret += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'X')
		nret += ft_hex(va_arg(args, unsigned int), 'X');
	else if (format == 'x')
		nret += ft_hex(va_arg(args, unsigned int), 'x');
	else if (format == '%')
		nret += ft_percent(format); //we pass the format string because there is no argument
	return (nret);
}

//!!! the format string is only %d,%i,%s... in this string the actual words, numbers are not included
int ft_printf(const char *format, ...)
{
	va_list args; // variable capable of storing a variable-length argument list
	int	i;
	int nret;

	va_start(args, format); //** initializes the list
	i = 0;
	nret = 0;
		while (format[i] != '\0') // this moves automatically forward in the string
		{
			if(format[i] == '%')
			{
				i++; // to arrive at the format specifier
				nret += ft_formatspecifier(args, format[i]); //this is correct!
				i++;
			}
			else // if printf("hello") whithout any formatting
			{
				nret += ft_printchar(format[i]); //? should I pass args as well?
				i++;
			}
		}
	va_end(args); //cleans up the variable argument list (variable with type va_list)
	return (nret);
}
/*
int main()
{
	ft_printf("%c%s%d%i%%%u%x%X", 'z', "hello", -10, -11, 12, 11, 123456789);
	printf("\n%c%s%d%i%%%u%x%X%p\n", 'z', "hello", -10, -11, 12, 11, 123456789, 1200); // test results with library printf function;
}

void print_ints(int num, ...)
{
	va_list args;

	va_start(args, num); // second position is always the name of the last required argument
	// it sets a pointer to the call stack where our variable arguments where stored
	// when the function was called

	for (int i=0; i < num; i++)
	{
		int value = va_arg(args, int); pull the arguments one by one in the order they are listed
		Each call to va_arg, updates that pointer to point to the next argument. 
		So, you are working strictly sequentially through the argument list. So, to skip an argument 
		you still need to read it, using va_arg, but you just write your program so it ignores it.
		printf("%d: %d\n", i, value);
	}
	va_end(args);
}

int main()
{
	print_ints(4, 3, 24, 26, 312);
	print_ints(2, 256, 512);
	print_ints(7, 1, 2, 3, 4, 5, 6);
}
*/
