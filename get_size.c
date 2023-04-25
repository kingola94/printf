#include "main.h"

/**
 * get_size - Calculates size to cast argument
 * @format: Formatted string.
 * @i: List of arguments.
 * Return: m
 */
int get_size(const char *format, int *i)
{
	int om = *i + 1;
	int m = 0;

	if (format[om] == 'l')
		m = S_LONG;
	else if (format[om] == 'h')
		m = S_SHORT;

	if (m == 0)
		*i = om - 1;
	else
		*i = om;

	return (m);
}
