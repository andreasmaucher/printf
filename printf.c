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

int ft_printf(const char *format, ...)
{
	va_list args; // variable capable of storing a variable-length argument list

	va_start(args, format); // initializes the list
	
	while (*format != '\0')
	{
		char write_string = (const char) va_arg(args, int); //va_arg returns the next argument in the list
		printf("%c", write_string);
	}
	va_end(args); //cleans up the variable argument list (variable with type va_list)
	return (0);
}

int main()
{
	char	str[] = "Hello";
	char	two[] = "bye";

	ft_printf(str,two);
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