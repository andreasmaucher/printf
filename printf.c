/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:39:38 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/05 10:39:39 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//** NOTE: printf returns the numbers of characters that are printed

int	ft_printchar(char c) //? does this work for numbers as well?
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
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int	ft_formatspecifier(va_list args, const char format)	// this is correct
{
	int nret;

	nret = 0;
	if (format == 's') //* = c
		nret += ft_printstr(va_arg(args, char *)); // this is correct
	return (nret);
}

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
				i++; // to arrive at the next char
				nret += ft_formatspecifier(args, format[i]); //this is correct!
				i++;
			}
			else
			{
				nret += ft_printchar(format[i]); //? should I pass args as well?
				i++;
			}
		}
	va_end(args); //cleans up the variable argument list (variable with type va_list)
	return (0);
}

int main()
{
	char	str[] = "%sHello";
	char	two[] = "%sbye";

	ft_printf(str,two); // test results with library printf function;
	// printf("%sHello");
}

/*
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
