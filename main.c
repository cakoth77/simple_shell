#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: A program that prints a prompt and reads a line of input from
 *              the user using the getline() function.
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **argv)
{
        char *prompt = "(Gitshell) $ ";
        char *lineptr;
        size_t m = 0;

/* declaring void variables */
        (void)ac; (void)argv;

        for (int a = 0; prompt[a] != '\0'; a++)
        {
                putchar(prompt[a]);
        }
	/* creating an infinite loop */
        while (1)
        {
                putchar(prompt[a]);
        }

        getline(&lineptr, &m, stdin);
        printf("%s\n", lineptr);
	/*free up allocated memory*/

        free(lineptr);
        return (0);
}
