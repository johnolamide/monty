#include "monty.h"

/**
 * get_int - gets character pointer to new string containing list
 * @num: number to convert to string
 * Return: character pointer to newly created string
 */
char *get_int(int num)
{
	unsigned int temp = _abs(num);
	int length = 0, num_1 = 0;
	char *ret;

	length = get_numbase_len(temp, 10);

	if (num < 0 || num_1 < 0)
		length++;
	ret = malloc(length + 1);
	if (ret == NULL)
		return (NULL);
	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_1 < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @num: integer number
 * Return: unsigned int absolute value of num
 */
unsigned int _abs(int num)
{
	if (num < 0)
		return (-(unsigned int)num);
	return ((unsigned int)num);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number
 * Return: int containing length of buffer
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num = num / base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert
 * @base: base of number used in he conversion
 * @buff: buffer to fill wih result of conversion
 * @buff_size: size of buffer
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';

	while (i >= 0)
	{
		rem = rem % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num = num / base;
		i--;
	}
}
