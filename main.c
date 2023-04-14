#include "main.h"
#include <stdio.h>
/**
 * main - printing a prompt and reading
 * @bc: integer
 * @argv: arguments
 * Return: Always 0
 */
int main(int bc, char **argv)
{
char *prompt = "(simpleshell) $ ";
/* variables for typed info and size allocation */
char *typed;
size_t m = 0;
/* void variables */
(void)bc;
(void)argv;
printf("%s", prompt);
/* to get what user types */
getline(&typed, &m, stdin);
free(typed);
return (0);
}

