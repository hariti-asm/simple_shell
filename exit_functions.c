#include "shell.h"

/**
 **strncpy - copies a string
 *@ds: the destination string to be copied to
 *@sr: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *strncpy(char *ds, char *sr, int n)
{
	int i, j;
	char *s = ds;

	i = 0;
	while (sr[i] != '\0' && i < n - 1)
	{
		ds[i] = sr[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			ds[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **strncat - concatenates two strings
 *@ds: the first string
 *@sr: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *strncat(char *ds, char *sr, int n)
{
	int i, j;
	char *s = ds;

	i = 0;
	j = 0;
	while (ds[i] != '\0')
		i++;
	while (sr[j] != '\0' && j < n)
	{
		ds[i] = sr[j];
		i++;
		j++;
	}
	if (j < n)
		ds[i] = '\0';
	return (s);
}

/**
 **strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
