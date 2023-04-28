#include "shell.h"
/**
 * interactive - returns true if shell is interactive mode
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(void)
{
return (isatty(STDIN_FILENO));
}
/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
int i;
for (i = 0; delim[i] != '\0'; i++)
{
if (c == delim[i])
return (1);
}
return (0);
}
/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
return (1);
else
return (0);
}
/**
 * string_to_int - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int string_to_int(char *str)
{
int i = 0;
int sign = 1;
int num = 0;
while (str[i] != '\0')
{
if (str[i] == '-')
sign = -1;
else if (str[i] >= '0' && str[i] <= '9')
num = num * 10 + (str[i] - '0');
else if (num)
break;
i++;
}
return (sign *num);
}
