#include "main.h"
/**
* reverse_string - reverses a string.
* @str: string
*/
void reverse_string(char *str)
{
	int x = 0;
	int y  = _strlen(str) - 1;
	char temp;

	while (x < y)
	{
		temp = str[x];
		str[x] = str[y];
		str[y] = temp;
		x++;
		y--;
	}
}
/**
* _itoa - converts number to string
* @num: number
* Return: character
*/
char *_itoa(int num)
{
	int i = 0;
	char *str = NULL;
	int isNegative = 0, len = 0;

	if (num == 0)
	{
		str = malloc(sizeof(char *) * 2);
		if (str == NULL)
			return (NULL);
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	len = digit_count(num);

	if (isNegative == 1)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	while (num != 0)
	{
		int rem = num % 10;

		str[i++] = rem + '0';
		num = num / 10;
	}
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';
	reverse_string(str);
	return (str);
}

/**
* digit_count - count the number of digits in a number.
* @num: number
* Return: number of digits
*/
int digit_count(int num)
{
	int count = 0;

	while (num != 0)
	{
		num = num / 10;
		++count;
	}
	return (count);
}
/**
* _atoi - converts string to integer.
* @str: string
* Return: 1
*/
int _atoi(const char *str)
{
	int i = 0, sign = 1;
	unsigned int num = 0;


	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		else
			break;
		i++;
	}
	return (num * sign);
}
