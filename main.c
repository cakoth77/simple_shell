#include "main.h"
/**
 * main - entry point
 * Return: Always 0
 * main - writes a string to the standard output stream
 * Return: count
 */

int main(void)
{
char *prompt = "(Wood) $ ";
char *lineptr = NULL, *lineptr_copy = NULL;
size_t m = 0;
ssize_t read_chars;
const char *delim = " \n";
int num_tokens = 0;
char *token;
int i;
char **argv;

while (1)
{
for (i = 0; prompt[i] != '\0'; i++)
{
our_putchar(prompt[i]);
}
read_chars = getline(&lineptr, &m, stdin);
if (read_chars == -1)
{
for (i = 0; "Exiting....\n"[i] != '\0'; i++)
{
our_putchar("Exiting....\n"[i]);
}
break;
}
if (our_strcmp(lineptr, "Exiting....\n") == 0)
{
break;
}
lineptr_copy = malloc(sizeof(char) * (read_chars + 1));
if (lineptr_copy == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}
our_strcpy(lineptr_copy, lineptr);
token = strtok(lineptr, delim);

while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;
argv = malloc(sizeof(char *) * num_tokens);
if (argv == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}
token = strtok(lineptr_copy, delim);

for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * our_strlen(token, 1024) + 1);
our_strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
execmd(argv);
}
for (i = 0; i < num_tokens; i++)
{
free(argv[i]);
}
free(lineptr_copy);
free(lineptr);
return (0);
}
