#include "main.h"
/**
 * _strlen - this function returns the length of a string
 *
 * @s: this is the string who's lenght must be determined
 *
 * Return: this function returns the lenght of a string
 */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strdup - duplicates a string
 *
 * @src: string to duplicate
 *
 * Return: pointer to new string, else NULL
 */
char *_strdup(const char *src)
{
	char *dest = malloc(_strlen(src) + 1);

	if (dest == NULL)
		return (NULL);
	_strcpy(dest, src);

	return (dest);
}
/**
 * _strcpy - function copies a string
 *
 * @dest: copied string
 * @src: original string
 *
 * Return: pointer to copied string
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - this function concatenates two strings
 *
 * @dest: is the first string
 * @src: is thesecond string
 *
 * Return: pointer to string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int count = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	count = i;
	while (src[j] != '\0')
	{
		dest[count + j] = src[j];
		j++;
	}
	dest[count + j] = '\0';
	return (dest);
}
/**
 * _itoa - converts number to string
 * @num: number
 * Return: character
 */
char *_itoa(size_t num)
{
	int i = 0, start = 0, end;
	size_t remainder = 0;
	char temp, *str = NULL;

	str = malloc(10);
	if (!str)
		return (NULL);

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	while (num != 0)
	{
		remainder = num % 10;
		if (remainder)
			str[i++] = remainder + '0';
		num = num / 10;
	}

	str[i] = '\0';

	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
/**
 * _strncmp - compares n number of chars in two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 *
 * Return: 0 if chars compared are equal, else differnece in chars not matching
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);

	while (n > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *) s1 - *(unsigned char *) s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
