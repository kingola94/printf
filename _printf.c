#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function that formats and prints output to stdout
 * @format: String containing the format specifications
 * Return: Number of characters printed on success, -1 on failure
 */
int _printf(const char *format, ...)
{
	int o, print = 0, print_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list om;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(om, format);

	for (o = 0; format && format[o] != '\0'; o++)
	{
		if (format[o] != '%')
		{
			buffer[buff_ind++] = format[o];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[o], 1);*/
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &o);
			width = get_width(format, &o, om);
			precision = get_precision(format, &o, om);
			size = get_size(format, &o);
			++o;
			print = handle_print(format, &o, om, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(om);

	return (print_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters to print
 * @buff_ind: Pointer to the index at which to add next character in buffer
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
