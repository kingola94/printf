#include "main.h"
/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int chars_written;

	va_start(args, format);
	chars_written = vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	if (chars_written >= 0 && chars_written < sizeof(buffer))
		write(1, buffer, chars_written);
	else
		return (-1);
	return (chars_written);
}
