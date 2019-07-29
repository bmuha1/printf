#include "holberton.h"

/**
 * Stoa - Print string with non-printable characters represented as ASCII
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: Always 0
 */
int Stoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	char *string = va_arg(valist, char *);
	char hex1, hex2;
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] >= 32 && string[i] < 127)
		{
			buffer_full(buffer, pos, n_printed);
			buffer[*pos] = string[i];
			(*pos)++;
		}
		else
		{
			buffer_full(buffer, pos, n_printed);
			buffer[*pos] = '\\';
			(*pos)++;
			buffer_full(buffer, pos, n_printed);
			buffer[*pos] = 'x';
			(*pos)++;
			hex1 = string[i] / 16;
			hex2 = string[i] % 16;
			if (hex1 < 10)
				hex1 += '0';
			else
				hex1 += 'A' - 10;
			if (hex2 < 10)
				hex2 += '0';
			else
				hex2 += 'A' - 10;
			buffer_full(buffer, pos, n_printed);
			buffer[*pos] = hex1;
			(*pos)++;
			buffer_full(buffer, pos, n_printed);
			buffer[*pos] = hex2;
			(*pos)++;
		}
	}
	return (0);
}