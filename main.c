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
        size_t n = 0;

/* declaring void variables */
        (void)ac; (void)argv;

        for (int i = 0; prompt[i] != '\0'; i++)
        {
                putchar(prompt[i]);
        }

        getline(&lineptr, &n, stdin);
        printf("%s\n", lineptr);

        free(lineptr);
        return (0);
}
