#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string to check for flags
 * @i: Pointer to the current index in the format string
 * Return: An integer representing the active flags
 */
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {1, 2, 4, 8, 16, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAG_CHARS[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAG_CHARS[j])
			{
				flags |= FLAG_VALUES[j];
				break;
			}
		}
		if (FLAG_CHARS[j] == 0)
		{
			break;
		}
	}
	*i = curr_i - 1;

	return (flags);
}
