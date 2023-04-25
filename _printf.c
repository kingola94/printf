#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format string
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int printed_chars = 0;
	va_list arg_list;
	char buffer[BUFF_SIZE];
	int buffer_index = 0;

	va_start(arg_list, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];

			if (buffer_index == BUFF_SIZE)
			{
				print_buffer(buffer, &buffer_index);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			const int flags = get_flags(format, &i);
			const int field_width = get_width(format, &i, arg_list);
			const int precision = get_precision(format, &i, arg_list);
			const int size_modifier = get_size(format, &i);
			++i;
			const int printed = handle_print(format, &i, arg_list,
					buffer, flags, field_width, precision, size_modifier);

			if (printed == -1)
			{
				va_end(arg_list);
				return (-1);
			}
			printed_chars += printed;

		}
	}
	print_buffer(buffer, &buffer_index);
	va_end(arg_list);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: character array
 * @buff_ind: pointer to buffer index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
	}

	*buff_ind = 0;

}
