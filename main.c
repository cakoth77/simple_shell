#include "main.h"
#include <stdio.h>
/**
 * main - printing a prompt and reading
 * @bc: integer
 * @argv: arguments
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	char *prompt = "(simpleshell) $ ";
/* variables for typed info and size allocation */
	char *lineptr;
	size_t m = 0;
/* void variables */
	(void)ac;
	(void)argv;
	while(1){
	printf("%s", prompt);
/* to get what user types */
	getline(&lineptr, &m, stdin);
	printf("%s", lineptr);
	free(lineptr);
	}
	return (0);
}

